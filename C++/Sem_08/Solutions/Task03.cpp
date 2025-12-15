#include <iostream>
#include <climits>

using namespace std;

unsigned short turnRightMostBitOne(int number)
{
    unsigned short size = sizeof(int) * CHAR_BIT;
    for (int i = 0; i < size; i++)
    {
        if (number & (1u << i))
        {
            number = number & ~(1u << i);
            break;
        }
    }

    return number;
}

int main()
{
    int number = 0;
    cin >> number;
    cout << turnRightMostBitOne(number);
    return 0;
}

