#include<iostream>
using namespace std;

//search for a medicine

struct Medicine {
    string name;  // اسم الدواء
    double price; // سعر الدواء
    int stock;    // الكمية المتاحة
};

Medicine medicines[100]; // مصفوفة لتخزين 100 دواء كحد أقصى

struct CartItem {
    int medicineIndex; // رقم الدواء في المصفوفة
    int quantity;      // الكمية التي اختارها المستخدم
};

struct user {

};

void searchForMedicine()
{
    char choice;
    string search;
    string category;
    string med;

    cout << "Enter the search type (c for category/n for name)";
    cin >> choice;

    switch(choice)
    {
        case 'n':
        cout << "search for medicine: ";
        cin >> search;

        for (int i = 0; i < 100; i++){
        if (medicines[i].name == search){
            cout << "Medicine : " << medicines[i].name << "\nPrice : " << medicines[i].price << endl;
            cout << "In stock : " << medicines[i].stock << endl;
            //addToCart(search);
        }
        }break;

        case 'c':
        cout << "which category you are looking for?" <<  endl;
        cin >> category;
        //displayMedicines(category);
        cout << "Enter the medicine you want" << endl;
        cin >> med;

        for (int i = 0; i < 100; i++){
            if (medicines[i].name == med){
                cout << "Medicine : " << medicines[i].name << "\nPrice : " << medicines[i].price << endl;
                cout << "In stock : " << medicines[i].stock << endl;
                //addToCart(med);
            }
            }
    }
}

int main()
{
    searchForMedicine();
    return 0;
}