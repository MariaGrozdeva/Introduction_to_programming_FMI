#include <iostream>
using namespace std;

unsigned int nthPowerOfTwo(unsigned int n)
{
    if (n > 31)
    {
        return 0; // some exception should be thrown here
    }

    return 1 << n;
}

int main()
{
    cout << nthPowerOfTwo(8);
}