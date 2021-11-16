// week 7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

void chainsaw(int arr[], int size)
{
    
    int temp = 0;
    for (int i = 0; i < size; i++)
    {
        temp = arr[i];
        int before = arr[i - 1];
        int after = arr[i + 1];
        bool in_it = false;
        if (i == 0)
        {
           in_it = (arr[i] >= after || arr[i] <= after);
        }
        else if (i == size - 1)
        {
           in_it = (arr[i] >= before || arr[i] <= before);
        }
        else
        {
            in_it = ((arr[i] >= before && arr[i] >= after) || (arr[i] <= before && arr[i] <= after));
        }
        
        
        
        if(!in_it)
        {
            arr[i] = arr[i + 1];   
            arr[i + 1] = temp;
        }

    }
    printArray(arr, size);
    
    
    
}

int main()
{
    
    int arr[] = {10, -10, -22, 11, 18};

    int size = sizeof(arr) / sizeof(int);
    chainsaw(arr, size);
}

// (index[1] >= index[0] && index[1] >= index[2]) || (index[1] <= index[0] && index[1] <= index[2]
//