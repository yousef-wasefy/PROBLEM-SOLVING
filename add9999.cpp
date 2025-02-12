#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <assert.h>
using namespace std;

//manual addition --> useful for very long strings

string add9999(string num,long long int carry = 9999)
{
    int digit;
    int n = num.length();

    for (int i = n - 1 ; i >= 0 ; i--)
    {
        digit = num[i] - '0' + carry % 10; // Add the last digit of carry
        carry /= 10;

        if (digit >= 10)
        {
            digit -= 10; // To handle overflow
            carry++;
        }
        
        num[i] = digit + '0';
    }

    if (carry > 0) num = to_string(carry) + num; // If any carry remains, prepend it

    return num;
}

int main()
{
    cout << add9999("129",2547) << endl; // "2676"
    cout << add9999("123456",2564534665898) << endl; // "2564534789354"
    cout << add9999("123456789123456789123456") << endl; // "123456789123456789133455"
    cout << add9999("999") << endl; // "10998"
    cout << add9999("") << endl; // "9999"
    return 0;
}