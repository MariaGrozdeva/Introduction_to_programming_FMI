#include <iostream>
using namespace std;

short countDigitOccurrences(unsigned n, short digit)
{
    short count = 0;
    while (n != 0)
    {
        if (n % 10 == digit)
        {
            count++;
        }
        n /= 10;
    }
    return count;
}
unsigned concatAtBack(unsigned n, short digit, short howManyTimes)
{
    for (size_t i = 0; i < howManyTimes; i++)
    {
        (n *= 10) += digit;
    }
    return n;
}

unsigned sortNumber(unsigned n)
{
    unsigned result = 0;
    for (size_t i = 1; i <= 9; i++)
    {
        short currentDigitCount = countDigitOccurrences(n, i);
        result = concatAtBack(result, i, currentDigitCount);
    }
    return result;
}

int main()
{
    cout << sortNumber(531261);
}