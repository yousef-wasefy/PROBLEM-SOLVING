#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <assert.h>
using namespace std;

//getting 2nd max in 2D array

const int ROWS = 3,COLS = 4;

int get2ndMax(int arr[ROWS][COLS])
{
    int max1 = arr[0][0];
    int max2 = arr[0][1];
    if (max2 > max1) swap(max1,max2);
    for (int i = 0 ; i < ROWS ; i++)
        for (int n = 0 ; n < COLS ; n++)
        {
            if (arr[i][n] > max1)
            {
                max2 = max1;
                max1 = arr[i][n];  
            }
            else if (arr[i][n] > max2 && max1 != arr[i][n]) max2 = arr[i][n];
        }
    return max2;
}

int main()
{
    int arr[ROWS][COLS] = {{20,21,7,-9},{2,1,39,0},{33,8,39,4}};

    cout << get2ndMax(arr) << endl; //33

    return 0;
}