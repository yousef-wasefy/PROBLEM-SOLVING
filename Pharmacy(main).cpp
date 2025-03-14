﻿#include<iostream>
#include <vector>
#include <string>
using namespace std;

//search for a medicine

//test

struct Medicine {
    string name;  // اسم الدواء
    string category;
    double price; // سعر الدواء
    int stock;    // الكمية المتاحة
    int quantity; //الكمية اللي اليوزر هياخدها 
};
Medicine medicines[100] = {
    {"paracetamol", "Painkiller", 23.0,40},
    {"ibuprofen", "Painkiller", 17.5,30},
    {"aspirin", "Painkiller", 31.0,20},
    {"amoxicillin", "Antibiotic", 46.0,15},
    {"azithromycin", "Antibiotic", 42.0,4},
    {"cough Syrup", "Cold & Flu", 19.0,50},
};
const int SIZE_OF_MEDICINES = sizeof(medicines) / sizeof(medicines[0]);
Medicine cart[SIZE_OF_MEDICINES];
int typecounter = 0; // used for different medicines taken

struct CartItem {
    int medicineIndex; // رقم الدواء في المصفوفة
    int quantity;      // الكمية التي اختارها المستخدم
};

struct user {
    string username, email, address, phone, role, password;
    int id;
};
#define max 100
user users[max];

string formatqunatity(int quantity)
{
    if (quantity == 0)
    {
        return "Out of stock";
    }
    return to_string(quantity);
}

void displayMedicine() { // دالة لعرض الادوية علي الشاشة
    for (int i = 0; i < SIZE_OF_MEDICINES; i++)
    {
        cout << "Name :" << medicines[i].name << endl;
        cout << "Price :" << medicines[i].price << endl;
        cout << "Quantities :" << medicines[i].stock << endl;
        cout << "********\n";
    }
}
    
//ندي
int medicineCount = 0;    // عدد الادويه المسجله

void AddMedicine() {    // داله لاضافه دواء جديد
    if (medicineCount >= 100) {
        cout << "we can't enter a new medicine the list is full" << endl;
        return;
    }
    else {
        Medicine newMedicine;
        cout << "enter the name of the medicine : " << endl;
        cin >> newMedicine.name;
        cout << "enter the price of the medicine : " << endl;
        cin >> newMedicine.price;
        cout << "enter the stock of the medicine : " << endl;
        cin >> newMedicine.stock;
        medicines[medicineCount] = newMedicine;
        medicineCount++;
        cout << "the medicine enter successfully" << endl;
    }
}

static void UpdateStock()    //  داله لتحديث مخزون الدواء
{
    if (medicineCount == 0) {
        cout << "there's no medicine added" << endl;
        return;
    }
    string SearchName;
    int NewStock;
    cout << "Enter the name of the medicine you wanna update : " << endl;
    cin >> SearchName;
    bool found = false;
    for (int i = 0;i < medicineCount;i++) {
        if (medicines[i].name == SearchName) {
            found = true;
            cout << "stock for " << medicines[i].stock << " : " << medicines[i].stock << endl;
            cout << "Enter new stock value " << endl;
            cin >> NewStock;
            if (NewStock >= 0) {
                medicines[i].stock = NewStock;
                cout << "update stock successfully: " << NewStock << endl;
            }
            else {
                cout << "stock can't be -ve" << endl;
            }
            return;
        }
    }
    if (!found) {
        cout << "medicine " << SearchName << " can't found" << endl;
    }
}

int cartSize = 0;
//يوسف هجرس
void addToCart(Medicine medicines, int quant) {
    if (cartSize < 100)
    {
        cart[cartSize] = medicines;
        cart[cartSize].quantity = quant;
        cartSize++;
        cout << "Added " << medicines.name << " to cart.\n";
    }
    else {
        cout << "Cart is full!\n";
    }
}

void FillInfo();
//يوسف احمد
void searchForMedicine()
{
    string choice;
    string search;
    string category;
    char add; //answer to add to the cart

    cout << "Enter the search type (by category/by name)";
    cin >> choice;

    switch (choice[0])
    {
    case 'n':
    case 'N':
        cout << "search for medicine: ";
        cin >> search;
        for (char &c : search)
        {
            c = tolower(c);
        }
        for (int i = 0; i < SIZE_OF_MEDICINES; i++) {
            if (medicines[i].name == search)
            {
                cout << "Medicine : " << medicines[i].name << "\nPrice : " << medicines[i].price << endl;
                cout << "In stock : " << medicines[i].stock << endl;

                cout << "would you add it to the cart?(y/n)\n";
                cin >> add;
                if (add == 'y' || add == 'Y')
                {
                    typecounter++;
                    cout << "How many you want?: ";
                    cin >> medicines[i].quantity;
                    //check first how many in stock!!
                    addToCart(medicines[i], medicines[i].quantity);
                }
            }
        }break;

    case 'c':
    case 'C':
        cout << "which category you are looking for?" << endl;
        cin >> category;
        for (int i = 0; i < SIZE_OF_MEDICINES;i++)
            if (medicines[i].category == category)
            {
                cout << "Medicine : " << medicines[i].name << "\nPrice : " << medicines[i].price << endl;
                cout << "In stock : " << medicines[i].stock << endl;
                cout << "=========" << endl;
            }
        cout << "Enter the medicine you want" << endl;
        cin >> search;

        for (int i = 0; i < SIZE_OF_MEDICINES; i++)
            if (medicines[i].name == search)
            {
                cout << "Medicine : " << medicines[i].name << "\nPrice : " << medicines[i].price << endl;
                cout << "In stock : " << medicines[i].stock << endl;

                cout << "would you add it to the cart?(y/n)\n";
                cin >> add;
                if (add == 'y' || add == 'Y')
                {
                    typecounter++;
                    cout << "How many you want?: ";
                    cin >> medicines[i].quantity;
                    addToCart(medicines[i], medicines[i].quantity);
                }
                ;
            }break;
    default:
        cout << "Invalid choice. Please enter 'n' for name or 'c' for category." << endl;
        break;
    }
}

//يوسف هجرس
void viewCart() {
    if (typecounter == 0) {
        cout << "Your cart is empty.\n";
        return;
    }

    cout << "Your Cart: \n";
    cout << "Name\tPrice\tQuantity\n";
    double total = 0;

    for (int i = 0; i < typecounter; i++) {
        if (cart[i].quantity > 0) {
            // Merge quantities of the same medicine
            for (int j = i + 1; j < typecounter; j++) {
                if (cart[j].name == cart[i].name) {
                    cart[i].quantity += cart[j].quantity;
                    cart[j].quantity = 0; // Mark as processed
                }
            }
            cout << "- " << cart[i].name << "\t\t" << cart[i].price << "egp\t(" << cart[i].quantity << ")\n";
            total += cart[i].price * cart[i].quantity;
        }
    }

    cout << "Total: " << total << "egp\n";
}

int usercount = 0;
void signـup() {
    user newuser;
    newuser.id = usercount + 1;
    cout << "enter your name:";
    cin >> newuser.username;
    cout << "enter your password:";
    cin >> newuser.password;
    cout << "enter your email:";
    cin >> newuser.email;
    cout << "enter your address:";
    cin >> newuser.address;
    cout << "enter your role (admin/customer):";
    cin >> newuser.role;
    users[usercount] = newuser;
    usercount++;
    cout << " signed up successfully. your id:" << newuser.id << endl;
}
bool logـin(string username, string password, string& role)
{
    for (int i = 0; i < usercount; i++) {
        if (users[i].username == username && users[i].password == password)
        {
            role = users[i].role;
            return true;
        }
    }

    return false;

}

struct LineItem
{
    string ItemName;
    double ItemPrice;
    int Count;
    double TotalLine;
};

struct Bill
{
    double totalAmount;
    double discount;
    double finalAmountWithVat;
    LineItem BillItems[100];
    int ItemCount;
    double ShippingFees;
    double VAT;
    double finalAmountWithoutVat;
};

Bill GenerateBill(Bill bill);
void PrintBill(Bill bill);

Bill GenerateBill(Bill bill)
{
    bill.totalAmount = 0;
    bill.discount = 0;
    bill.ShippingFees = 30;
    bill.VAT = 17.5;
    for (int i = 0; i < bill.ItemCount; i++)
    {
        bill.BillItems[i].TotalLine = bill.BillItems[i].ItemPrice * bill.BillItems[i].Count;
        bill.totalAmount += bill.BillItems[i].TotalLine;

    }
    if (bill.totalAmount > 30 && bill.totalAmount <= 55)
    {
        bill.discount = 10;
    }
    else if (bill.totalAmount > 55 && bill.totalAmount <= 75)
    {
        bill.discount = 20;
    }
    else if (bill.totalAmount > 70)
    {
        bill.discount = 25;
        bill.ShippingFees = 0;
    }

    if (bill.discount > 0)
    {
        double discountedval = ((100 - bill.discount) / 100);
        bill.finalAmountWithoutVat = bill.totalAmount * discountedval;
    }
    else
    {
        bill.finalAmountWithoutVat = bill.totalAmount;
    }
    if (bill.VAT > 0)
    {
        double vattedval = ((100 + bill.VAT) / 100);
        bill.finalAmountWithVat = bill.finalAmountWithoutVat * vattedval;
    }
    else
    {
        bill.finalAmountWithVat = bill.finalAmountWithoutVat;
    }
    return bill;
}

void PrintBill(Bill bill)
{
    cout << "Medicine Name\tQuantity\tPrice\tTotal Price\n";
    for (int i = 0; i < typecounter; i++) {
        if (cart[i].quantity > 0) {
            // Merge quantities of the same medicine
            for (int j = i + 1; j < typecounter; j++) {
                if (cart[j].name == cart[i].name) {
                    cart[i].quantity += cart[j].quantity;
                    cart[j].quantity = 0; // Mark as processed
                }
            }
            cout << bill.BillItems[i].ItemName << "\t\t ";
            cout << bill.BillItems[i].Count << "\t\t";
            cout << bill.BillItems[i].ItemPrice << "\t";
            cout << bill.BillItems[i].TotalLine << "\n";
        }
    }
    cout << "Total Price Before Discount& VAT: " << bill.totalAmount << "\n";
    cout << "Discount: " << bill.discount << "%\n";
    cout << "Total After Discount: " << bill.finalAmountWithoutVat << "\n";
    cout << "VAT: " << bill.VAT << "%\n";
    cout << "Total After VAT: " << bill.finalAmountWithVat << "\n";
    cout << "Shipping Fees: " << bill.ShippingFees << "\n";
    cout << "Total Price including shipping fees: " << bill.finalAmountWithVat + bill.ShippingFees << "\n";
}

LineItem items[SIZE_OF_MEDICINES];
Bill filll;

void FillInfo()
{
    for (int i = 0; i < typecounter; i++)
    {
        filll.BillItems[i].ItemName= cart[i].name;
        filll.BillItems[i].Count= cart[i].quantity;
        filll.BillItems[i].ItemPrice= cart[i].price;
    }
    filll.ItemCount = typecounter;
    Bill saveGenBill = GenerateBill(filll);
    PrintBill(saveGenBill);
}

int main()
{
    int Choice;
    int answer; //ask the user what does he want to do
    int choice;
    string username, password, role;
    do {
        cout << "Choose from 1 to 5\n";
        cout << "1. sign up" << endl;
        cout << "2. sign in" << endl;
        cout << "3. search for a medicine" << endl;
        cout << "4. view cart" << endl;
        cout << "5.checkout& payment" << endl;
        cout << "6. leave out" << endl;
        cin >> answer;
        switch (answer)
        {
        case 1:
            signـup();
            if (users->role == "admin")
        do {           //for admins only!!!
        cout << endl << "Pharmacy System" << endl;
        cout << "1) add new medicine" << endl;
        cout << "2) Update Stock" << endl;
        cout << "3) exit" << endl;
        cout << "enter your choice" << endl;
        cin >> Choice;
        switch (Choice) {
        case 1:
            AddMedicine();
            break;
        case 2:
            UpdateStock();
            break;
        case 3:
            cout << "exiting successfully" << endl;
            break;
        default:
            cout << "incorrect choice,try again" << endl;
        }
        } while (Choice != 3);
            break;
        case 2:
            cout << "enter your name:";
            cin >> username;
            cout << "enter your password:";
            cin >> password;
            if (logـin(username, password, role)) {
                cout << "log in successfully. your role is " << role << endl;
            }
            else
                cout << "your username or password is not correct." << endl;
            break;
        case 3:
            searchForMedicine();
            break;
        case 4:
            viewCart();
            break;
        case 5:
            FillInfo();
            break;
        default:
            break;
        }
    } while (answer != 6);
    
    return 0;
}