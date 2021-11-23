#include <iostream>
using namespace std;

void returnBigLetters(const char arr[])
{
    int len = strlen(arr);
    for (int i = 0; i < len; i++)
    {  
        if (arr[i] >= 'à' && arr[i] <= 'z')
        {
            
            char c = arr[i];
            c -= 32;
            cout << c;
        }
        else
            cout << arr[i];
    }
}

int main()
{
    const int maxSize = 64;
    char arr[maxSize];

    cin.getline(arr, maxSize);

    returnBigLetters(arr);
}
