#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <assert.h>
using namespace std;

int product(int n1,int n2)
{
    int p;
    for (int i = 0; i < n2; i++)
    {
        p += n1;
    }
    return p;
}

int main ()
{
    int n1,n2; cout << "Enter two numbers: \n"; cin >> n1 >> n2;
    cout << "Product: " << product(n1,n2);

    return 0;
}