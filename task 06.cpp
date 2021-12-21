
#include <iostream>
using namespace std;

void smallest(int* arr, int len, int small)
{
    if (len < 0)
        cout << small;
    else
    {
        if (small > *arr)
            small = *arr;
        smallest(++arr, --len, small);
    }
}
int main()
{
    int const maxSize = 5;
    int arr[maxSize];

    for (int i = 0; i < maxSize; i++)
    {
        cin >> arr[i];
    }
    int len = sizeof(arr) / sizeof(int);
    
    smallest(arr, maxSize - 1, arr[0]);
}
