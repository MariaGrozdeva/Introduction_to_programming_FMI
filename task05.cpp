
#include <iostream>
using namespace std;

void returnNumber(const char arr[])
{
    int len = strlen(arr);
    
    for (int i = 0; i < len; i++)
    {
        

        if (arr[i] >= '0' && arr[i] <= '9')
            cout << arr[i];
    }
}
int main()
{
    const int maxSize = 64;
    char arr[maxSize];

    cin.getline(arr, maxSize);

    returnNumber(arr);
}
