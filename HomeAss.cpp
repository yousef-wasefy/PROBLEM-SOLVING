#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <assert.h>
using namespace std;

const int NUMBER_OF_PRODUCTS = 10;

struct product
{
    string serialNum;
    int quantity;
    float totalSales;
    float price;
};

void InputProducts(product products[], int num_Of_Products);
void productsLessThan(int quant, product products[],int num_Of_Products);
void getIndexOfHighestSales( product products[],int num_Of_Products);
void displayProduct( product products[],int num_Of_Products);
void discountFor6ItemsLeft( product products[], int num_Of_Products);
void PriceLessThan(product products[], int numOfProducts, int amount, int &count);
int menu();

int main()
{
    product products[NUMBER_OF_PRODUCTS];
    int quant;
    int choice;
    char answer;
    int num_Of_Products;

    cout << "PLease, Enter the number of products: ";
    cin >> num_Of_Products;

    InputProducts(products, num_Of_Products);

    do
    {
        switch(choice = menu())
        {
        case 1:
            cout << "Serial Numbers of the Products that has less quantity than a value entered by the user:\n";
            cout << "Please enter the quantity: "; cin >> quant;
            productsLessThan(quant, products, num_Of_Products);break;
        case 2:
            getIndexOfHighestSales(products, num_Of_Products);
            break;
        case 3:
            discountFor6ItemsLeft(products, num_Of_Products);break;    
        case 4:
            displayProduct(products, num_Of_Products);
            break;
        case 5:
            int count, amount;

            cout << "Enter the amount: "; // the price of products shouldn't be less than this amount.
            cin >> amount;

            PriceLessThan(products, num_Of_Products, amount, count);

            cout << "The number of products with price less than " << amount << " is " << count << endl;
            break;
        default : cout
             << "Invalid Choice! please try again.";
            answer = 'y';
            continue;
        }
        
        cout << "\nDo you want to Apply Another function, Press 'Y' or 'y' for yes, any other key to stop: ";
        cin >> answer;
    } while(answer == 'y' || answer == 'Y');

    return 0;
}

int menu()
{
    int choice;
    cout << "Please enter a number:" << endl;
    cout << "Press 1 to get products that have less quantity than a certain value." << endl;
    cout << "Press 2 to Get Product with the highest sales." << endl;
    cout << "Press 3 to Apply 50% discount for products that have quantity less than 6." << endl;
    cout << "Press 4 to Display all the products." << endl;
    cout << "Press 5 to get products less than a certain amount." << endl;
    cin >> choice;
    return choice;
}

void InputProducts (product products[],int num_Of_Products)
{
    cout << "Please enter the " << num_Of_Products << " products:" << endl;
    for (int i = 0 ; i < num_Of_Products ; i++)
    {
        cout << "Enter values of product #" << (i+1) << endl;
        cout << "Serial number: "; cin >> products[i].serialNum;
        cout << "quantity: "; cin >> products[i].quantity;
        cout << "sales: "; cin >> products[i].totalSales;
        cout << "Price: "; cin >> products[i].price;
    }
    
}

void displayProduct(product products[], int num_Of_Products)
{
    for (int i = 0 ; i < num_Of_Products ; i++)
    {
        cout << "Enter values of product #" << (i+1) << endl;
        cout << "Serial number: "; cout << products[i].serialNum << endl;
        cout << "quantity: "; cout << products[i].quantity << endl;
        cout << "sales: "; cout << products[i].totalSales << endl;
        cout << "Price: "; cout << products[i].price << endl;
    }
}

void productsLessThan(int quant, product products[], int num_Of_Products)
{ 
    for (int i = 0 ; i < num_Of_Products ; i++)
    {
        if (products[i].quantity < quant) 
            cout << "Product " << products[i].serialNum << endl;
    }
}

void discountFor6ItemsLeft(product products[], int num_Of_Products)
{
    cout << "Discount applied for product(s) ";
    for (int i = 0 ; i < num_Of_Products ; i++)
    {
        if (products[i].quantity < 6) 
        { 
            products[i].price *= 0.5;
            cout << (i+1) << " ";
        }
    }
}

void getIndexOfHighestSales(product products[], int num_Of_Products)
{
    bool isHigher = false;
    float highest = -1;
    int index[num_Of_Products]; //for getting index of highest product(s)

    for (int i = 0 ; i < num_Of_Products ; i++)
    {
        if (products[i].totalSales > highest) 
        {
            highest = products[i].totalSales;
            index[i] = i;
        }
        else if (products[i].totalSales == highest) index[i] = i;
    }

    cout << "Product with highest sales\nProduct(s) ";
    for (int j = 0 ; j < num_Of_Products ; j++) 
    { 
        isHigher =  false;
        for (int i = 0 ; i < num_Of_Products ; i++)
        {
            if (products[j].totalSales >= products[i].totalSales) isHigher = true;
            else { 
                isHigher =  false;
                break;
            }
        }

        if (isHigher) cout << (index[j] + 1) << " ";
    }
}

void PriceLessThan(product products[], int num_Of_Products, int amount, int &count)
{
    count = 0;
    for (int i = 0; i < num_Of_Products; i++)
    {
        if (products[i].price < amount)
            count++;
    }
}