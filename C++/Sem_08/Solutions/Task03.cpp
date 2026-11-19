#include <iostream>
#include <climits>

using namespace std;

int clearRightmostSetBit(int number)
{
    int size = sizeof(int) * CHAR_BIT;
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

int clearRightmostSetBitSimpler(int number)
{
    return number & (number- 1);
}

int main()
{
    int number = 0;
    cin >> number;
    cout << clearRightmostSetBitSimpler(number);
    return 0;
}

