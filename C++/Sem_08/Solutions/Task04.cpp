#include <iostream>
using namespace std;

int extractLastKBits(int number, unsigned short bitCount)
{
    if (bitCount == 0)
    {
        return 0;
    }

    int mask = 1;
    for (int i = 0; i < bitCount - 1; i++)
    {
        mask = (mask << 1) | 1;
    }

    return number & mask;
}

int main()
{
    int n = 0;
    unsigned short bitCount = 0;
    cin >> n >> bitCount;
    cout << extractLastKBits(n, bitCount);
    return 0;
}

