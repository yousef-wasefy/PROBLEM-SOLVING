#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <assert.h>
using namespace std;

// struct product
// {
//     float basePrice;
//     float taxes;
//     float maxPrice;
// };

// int netPrice(product p)
// {
//     int result = p.basePrice + p.basePrice * (p.taxes/100);
//     return result;
// }

const int NUMBER_OF_PRODUCTS = 4;

string serialNum[NUMBER_OF_PRODUCTS];
int quantity[NUMBER_OF_PRODUCTS];
float totalSales[NUMBER_OF_PRODUCTS];

void InputProducts ();
void productsLessThan(int quant);
void getIndexOfHighestSales();

int main()
{
	// product p[3];

    // for(int i = 0 ; i < 3 ; i++)
    // {
    //     cout << "Data of product #" << (i+1) << endl;
    //     cout << "Enter base price of product : ";
    //     cin >> p[i].basePrice;
    //     cout << "Enter taxes of product : ";
    //     cin >> p[i].taxes;
    //     cout << "Enter maximum price of the belonging production line : ";
    //     cin >> p[i].maxPrice;
    
    //     cout << "Product net price : " << netPrice(p[i]) << endl;

    //     if (netPrice(p[i]) > p[i].maxPrice)
    //         cout << "Product net price exceeds production line maximum price" << endl;
    //     else 
    //         cout << "Product net price is accepted" << endl;
    // }
    int quant;
    InputProducts ();
    cout << "Serial Numbers of the Products that has less quantity than a value entered by the user:\n";
    cout << "Please enter the quantity: "; cin >> quant;
    productsLessThan(quant);
    getIndexOfHighestSales();

    return 0;
}

void InputProducts ()
{
    cout << "Please enter the four products:" << endl;
    for (int i = 0 ; i < NUMBER_OF_PRODUCTS ; i++)
    {
        cout << "Enter values of product #" << (i+1) << endl;
        cout << "Serial number: "; cin >> serialNum[i];
        cout << "qunatity: "; cin >> quantity[i];
        cout << "sales: "; cin >> totalSales[i];
    }
    
}

void productsLessThan(int quant)
{
    
    for (int i = 0 ; i < NUMBER_OF_PRODUCTS ; i++)
    {
        if (quantity[i] < quant) 
            cout << "Product " << serialNum[i] << endl;
    }

}

void getIndexOfHighestSales()
{
    float highest = totalSales[0];
    int index;
    for (int i = 0 ; i < NUMBER_OF_PRODUCTS ; i++)
    {
        if (totalSales[i] > highest) 
        {
            highest = totalSales[i];
            index = i;
        }
    }

    cout << "Product with highest sales\nProduct " << (index + 1);
}