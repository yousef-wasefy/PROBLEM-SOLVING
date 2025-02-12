#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <assert.h>
using namespace std;

vector<string> sub_strings(string str)
{
    vector<string> arr;
    string res;
    for(int i = 0 ; i < str.length() ; i++)
    {
        res = "";
        for(int j = 0 ; j < str.length() - i ; j++)
        {
            res += str[i+j];
            arr.push_back(res);
        }
    }
    return arr;
}

int main()
{
    vector<string> res = sub_strings("123a");
    for (string s : res) cout << s << endl;
    return 0;
}