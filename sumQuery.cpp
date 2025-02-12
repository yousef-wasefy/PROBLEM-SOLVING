#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <assert.h>
using namespace std;

//accumulating the array

vector<int> prefixSum(vector<int> arr)
{
    vector<int> prefix(arr.size());
    for (int i = 0 ; i < arr.size() ; i++)
    {
        prefix[i] = prefix[i-1] + arr[i];
    }
    return prefix;
}

int querySum(vector<int> prefix,int start, int end)
{
    return prefix[end] - prefix[start - 1];
}

int main()
{
    vector<int> arr = prefixSum({1,2,5,0,4});

    cout << querySum(arr,0,4) << endl; //12
    cout << querySum(arr,2,4) << endl; //9
    cout << querySum(arr,0,1) << endl; //3
    return 0;
}