#include<iostream>
using namespace std;

//search for a medicine

struct Medicine {
    string name;  // اسم الدواء
    string category;
    double price; // سعر الدواء
    // int stock;    // الكمية المتاحة
    
};

// Medicine medicines[100]; // مصفوفة لتخزين 100 دواء كحد أقصى

struct CartItem {
    int medicineIndex; // رقم الدواء في المصفوفة
    int quantity;      // الكمية التي اختارها المستخدم
};

Medicine medicines[] = {
    {"Paracetamol", "Painkiller", 5.0},
    {"Ibuprofen", "Painkiller", 7.5},
    {"Aspirin", "Painkiller", 6.0},
    {"Amoxicillin", "Antibiotic", 10.0},
    {"Azithromycin", "Antibiotic", 12.0},
    {"Cough Syrup", "Cold & Flu", 8.0}
};

int totalMedicines = sizeof(medicines) / sizeof(medicines[0]);

void searchForMedicine()
{
    char choice;
    string search;
    string category;
    string med;
    char add; //answer to add to the cart

    cout << "Enter the search type (by category/by name)";
    cin >> choice;

    switch(choice)
    {
        case 'n':
        case 'N':
        cout << "search for medicine: ";
        cin >> search;

        for (int i = 0; i < totalMedicines; i++){
        if (medicines[i].name == search)
        {
            cout << "Medicine : " << medicines[i].name << "\nPrice : " << medicines[i].price << endl;
            // cout << "In stock : " << medicines[i].stock << endl;

            // cout << "would you add it to the cart?(y/n)\n";
            // cin >> add;
            // if (add == 'y' || add == 'Y')
            //     //addToCart(search);
            // ;
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
                // cout << "In stock : " << medicines[i].stock << endl;
                cout << "=========" << endl;
            }
        cout << "Enter the medicine you want" << endl;
        cin >> med;

        for (int i = 0; i < totalMedicines; i++)
            if (medicines[i].name == med)
            {
                cout << "Medicine : " << medicines[i].name << "\nPrice : " << medicines[i].price << endl;
                // cout << "In stock : " << medicines[i].stock << endl;

                // cout << "would you add it to the cart?(y/n)\n";
                // cin >> add;
                // if (add == 'y' || add == 'Y')
                //     //addToCart(med);
                // ;
            }break;
        default:
            cout << "Invalid choice. Please enter 'n' for name or 'c' for category." << endl;
            break;
    }
}

int main()
{
    searchForMedicine();
    return 0;
}