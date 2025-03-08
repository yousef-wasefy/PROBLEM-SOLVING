#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <assert.h>
using namespace std;

//test

const int NUMBER_OF_PRODUCTS = 4;

struct product
{
    string serialNum;
    int quantity;
    float totalSales;
    float price;
}products[NUMBER_OF_PRODUCTS];

void InputProducts();
void productsLessThan(int quant);
void getIndexOfHighestSales();
void displayProduct();
void discountFor6ItemsLeft();
int menu();

int main()
{
    int quant;
    int choice;
    char answer;
    InputProducts();
    do
    {
        switch(choice = menu())
        {
        case 1:
            cout << "Serial Numbers of the Products that has less quantity than a value entered by the user:\n";
            cout << "Please enter the quantity: "; cin >> quant; 
            productsLessThan(quant);break;
        case 2:
            getIndexOfHighestSales();break;
        case 3:
            discountFor6ItemsLeft();break;    
        case 4: 
            displayProduct();break;
        default:
            cout << "Invalid Choice! please try again.";
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
    cin >> choice;
    return choice;
}

void InputProducts ()
{
    cout << "Please enter the four products:" << endl;
    for (int i = 0 ; i < NUMBER_OF_PRODUCTS ; i++)
    {
        cout << "Enter values of product #" << (i+1) << endl;
        cout << "Serial number: "; cin >> products[i].serialNum;
        cout << "qunatity: "; cin >> products[i].quantity;
        cout << "sales: "; cin >> products[i].totalSales;
        cout << "Price: "; cin >> products[i].price;
    }
    
}

void displayProduct()
{
    for (int i = 0 ; i < NUMBER_OF_PRODUCTS ; i++)
    {
        cout << "Enter values of product #" << (i+1) << endl;
        cout << "Serial number: "; cout << products[i].serialNum << endl;
        cout << "qunatity: "; cout << products[i].quantity << endl;
        cout << "sales: "; cout << products[i].totalSales << endl;
        cout << "Price: "; cout << products[i].price << endl;
    }
}

void productsLessThan(int quant)
{ 
    for (int i = 0 ; i < NUMBER_OF_PRODUCTS ; i++)
    {
        if (products[i].quantity < quant) 
            cout << "Product " << products[i].serialNum << endl;
    }
}

void discountFor6ItemsLeft()
{
    cout << "Discount applied for product(s) ";
    for (int i = 0 ; i < NUMBER_OF_PRODUCTS ; i++)
    {
        if (products[i].quantity < 6) 
        { 
            products[i].price *= 0.5;
            cout << (i+1) << " ";
        }
    }
}

void getIndexOfHighestSales()
{
    bool isHigher = false;
    float highest = -1;
    int index[NUMBER_OF_PRODUCTS]; //for getting index of highest product(s)

    for (int i = 0 ; i < NUMBER_OF_PRODUCTS ; i++)
    {
        if (products[i].totalSales > highest) 
        {
            highest = products[i].totalSales;
            index[i] = i;
        }
        else if (products[i].totalSales == highest) index[i] = i;
    }

    cout << "Product with highest sales\nProduct(s) ";
    for (int j = 0 ; j < NUMBER_OF_PRODUCTS ; j++) 
    { 
        isHigher =  false;
        for (int i = 0 ; i < NUMBER_OF_PRODUCTS ; i++)
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