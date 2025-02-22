#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <assert.h>
using namespace std;

struct product
{
    float basePrice;
    float taxes;
    float maxPrice;
};

int netPrice(product p)
{
    int result = p.basePrice + p.basePrice * (p.taxes/100);
    return result;
}

int main()
{
	product p[3];

    for(int i = 0 ; i < 3 ; i++)
    {
        cout << "Data of product #" << (i+1) << endl;
        cout << "Enter base price of product : ";
        cin >> p[i].basePrice;
        cout << "Enter taxes of product : ";
        cin >> p[i].taxes;
        cout << "Enter maximum price of the belonging production line : ";
        cin >> p[i].maxPrice;

        cout << "Product net price : " << netPrice(p[i]) << endl;

        if (netPrice(p[i]) > p[i].maxPrice)
            cout << "Product net price exceeds production line maximum price" << endl;
        else 
            cout << "Product net price is accepted" << endl;
    }
    
    return 0;
}