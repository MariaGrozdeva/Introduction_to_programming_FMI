#include <iostream>
#include <climits>

using namespace std;

unsigned short countOnes(int number)
{
    unsigned short counter = 0;
    unsigned short size = sizeof(int) * CHAR_BIT;

    for (int i = 0; i < size; i++)
    {
        if (number & (1u << i))
        {
            counter++;
        }
    }

    return counter;
}

int main()
{
    int number = 0;
    cin >> number;
    cout << countOnes(number);
    return 0;
}

