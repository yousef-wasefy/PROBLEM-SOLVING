#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

void _sort(int arr[],int n)
{
  bool swapped;
  for (int j = 0 ; j < n ; j++)
  {
    swapped = false;
    for (int i = n-1 ; i > 0 ; i--)
    {
      if (arr[i-1] > arr[i])
      {
        swap(arr[i-1],arr[i]);
        swapped = true;
      }
    }
    if (!swapped) break;
  }
}

int main() 
{
  int arr[] = {15,9};
  int n = sizeof(arr) / sizeof(arr[0]);

  _sort(arr, n);

  // Print sorted array
  for (int i = 0; i < n; i++) 
  {
    cout << arr[i] << " ";
  }

  return 0;
}
