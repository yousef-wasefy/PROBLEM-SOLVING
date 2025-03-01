#include<iostream>
#include<vector>
using namespace std;

//search for a medicine

struct Medicine {
    string name;  // اسم الدواء
    string category;
    double price; // سعر الدواء
    int stock;    // الكمية المتاحة
    int quantity; //الكمية اللي اليوزر هياخدها 
};

int counter = 0; // used for different medicines taken

struct CartItem {
    int medicineIndex; // رقم الدواء في المصفوفة
    int quantity;      // الكمية التي اختارها المستخدم
};

Medicine medicines[] = {
    {"Paracetamol", "Painkiller", 5.0,40},
    {"Ibuprofen", "Painkiller", 7.5,30},
    {"Aspirin", "Painkiller", 6.0,20},
    {"Amoxicillin", "Antibiotic", 10.0,15},
    {"Azithromycin", "Antibiotic", 12.0,4},
    {"Cough Syrup", "Cold & Flu", 8.0,50},
};

const int SIZE = sizeof(medicines)/sizeof(medicines[0]);

string formatqunatity(int quantity)
{
 if (quantity == 0)
 {
  return "Out of stock";
 }
 return to_string(quantity);
}

void displayMedicine() { // دالة لعرض الادوية علي الشاشة
 for (int i = 0; i < SIZE; i++)
 {
  cout << "Name :" << medicines[i].name<< endl;
  cout << "Price :" << medicines[i].price<< endl;
  cout << "Quantities :" << medicines[i].stock<< endl;
  cout << "********\n";
 }
}

int totalMedicines = sizeof(medicines) / sizeof(medicines[0]);

Medicine cart[SIZE];
int cartSize = 0;
//يوسف هجرس
void addToCart(Medicine medicines,int quant) {
    if (cartSize < 100) 
    {
        cart[cartSize++] = medicines;
        cout << "Added " << medicines.name << " to cart.\n";
    } else {
        cout << "Cart is full!\n";
    }
}
//يوسف احمد
void searchForMedicine()
{
    string choice;
    string search;
    string category;
    string med;
    char add; //answer to add to the cart

    cout << "Enter the search type (by category/by name)";
    cin >> choice;

    switch(choice[0])
    {
        case 'n':
        case 'N':
        cout << "search for medicine: ";
        cin >> search;

        for (int i = 0; i < totalMedicines; i++){
        if (medicines[i].name == search)
        {
            cout << "Medicine : " << medicines[i].name << "\nPrice : " << medicines[i].price << endl;
            cout << "In stock : " << medicines[i].stock << endl;

            cout << "would you add it to the cart?(y/n)\n";
            cin >> add;
            if (add == 'y' || add == 'Y')
            {
                counter++;
                cout << "How many you want?: ";
                cin >> medicines[i].quantity;
                //check first how many in stock!!
                addToCart(medicines[i],medicines[i].quantity);
            }
        }
        }break;

        case 'c':
        case 'C':
        cout << "which category you are looking for?" <<  endl;
        cin >> category;
        for (int i = 0; i < totalMedicines; i++)
            if (medicines[i].category == category)
            {
                cout << "Medicine : " << medicines[i].name << "\nPrice : " << medicines[i].price << endl;
                cout << "In stock : " << medicines[i].stock << endl;
                cout << "=========" << endl;
            }
        cout << "Enter the medicine you want" << endl;
        cin >> med;

        for (int i = 0; i < totalMedicines; i++)
            if (medicines[i].name == med)
            {
                cout << "Medicine : " << medicines[i].name << "\nPrice : " << medicines[i].price << endl;
                cout << "In stock : " << medicines[i].stock << endl;

                cout << "would you add it to the cart?(y/n)\n";
                cin >> add;
                if (add == 'y' || add == 'Y')
                {
                    counter++;
                    cout << "How many you want?: ";
                    cin >> medicines[i].quantity;
                    addToCart(medicines[i],medicines[i].quantity);
                }
                ;
            }break;
        default:
            cout << "Invalid choice. Please enter 'n' for name or 'c' for category." << endl;
            break;
    }
}

void viewCart();

void askUserToViewCart()
{
    char view;
    cout << "Do you want to view your cart?(y/n)";
    cin >> view;
    if (view == 'y' || view == 'Y')
        viewCart();
    
}

//يوسف هجرس
void viewCart() {
    if (cartSize == 0) {
        cout << "Your cart is empty.\n";
        return;
    }
    
    cout << "Your Cart: \n";
    double total = 0;
    for (int i = 0; i < cartSize; i++) {
        cout << "- " << cart[i].name << " ($" << cart[i].price << ")\n";
        total += cart[i].price;
    }
    cout << "Total: $" << total << "\n";
}

#define max 100
struct user {
 string username, email, address, phone, role, password;
 int id;
};
user users[max];
int usercount = 0;
void singـup() {
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
 cout << " log in successfully. your id:" << newuser.id << endl;
}
bool logـin(string username, string password, string &role)
{
 for (int i = 0;i < usercount;i++) {
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
    double finalAmount;
    LineItem BillItems[100];
    int ItemCount;
    double ShippingFees;
};

void PrintBill(Bill bill);
Bill GenerateBill(Bill bill);
void checkOut();

Bill GenerateBill(Bill bill)
{
    bill.totalAmount = 0;
    for (int i = 0; i < bill.ItemCount; i++)
    {
        bill.BillItems[i].TotalLine = bill.BillItems[i].ItemPrice * bill.BillItems[i].Count;
        bill.totalAmount += bill.BillItems[i].TotalLine;
    }
    if (bill.discount > 0)
    {
        double discountedval = ((100 - bill.discount) / 100.0);
        bill.finalAmount = bill.totalAmount * discountedval;
    }
    else
    {
        bill.finalAmount = bill.totalAmount;
    }
    return bill;
}

void PrintBill(Bill bill)
{
    cout << "Medicine Name\tQuantity\tPrice\tTotal Price\n";
    for (int i = 0; i < bill.ItemCount; i++)
    {
        cout << bill.BillItems[i].ItemName << "\t\t";
        cout << bill.BillItems[i].Count << "\t\t";
        cout << bill.BillItems[i].ItemPrice << "\t";
        cout << bill.BillItems[i].TotalLine << "\n";
    }
    cout << "Total Price Before Discount: " << bill.totalAmount << "\n";
    cout << "Discount: " << bill.discount << "\n";
    cout << "Total After Discount: " << bill.finalAmount << "\n";
    cout << "Shipping Fees: " << bill.ShippingFees << "\n";
    cout << "Total Price including shipping fees: " << bill.finalAmount + bill.ShippingFees << "\n";
}

LineItem items[SIZE];
Bill bill;

void checkOut()
{
    for(int i = 0 ; i < cartSize ; i++)
    {
        items[i].ItemName = cart[i].name;
        items[i].Count = cart[i].quantity;
        items[i].ItemPrice = cart[i].price;
        bill.BillItems[i] = items[i];

    }
    bill.ItemCount = counter;
    bill.discount = 0; // You can set discount value here
    bill.ShippingFees = 5.0; // You can set shipping fees here
    Bill genBill;
    genBill = GenerateBill(bill);
    PrintBill(genBill);
}

int main()
{
    int choice;
    string username, password, role;
    do {
    cout << "\t**user mangement system**\n";
    cout << "1:log in\n";
    cout << "2:sing up\n";
    cin >> choice;
    switch (choice) {
    case 1:
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
  case 2:
   singـup();
   break;
  }

 } while (choice == 1 || choice == 2);
    searchForMedicine();
    askUserToViewCart();
    checkOut();
    return 0;
}