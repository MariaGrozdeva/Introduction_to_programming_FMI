#include <iostream> 
using namespace std;

bool checkBit(unsigned int n, unsigned short index)
{
    return 1 & (n >> index);
}

unsigned int setBit(unsigned int n, unsigned short index)
{
    return n |= (1 << index);
}

unsigned int clearBit(unsigned int n, unsigned short index)
{
    return n &= ~(1 << index);
}

unsigned int toggleBit(unsigned int n, unsigned short index)
{
    return n ^= (1 << index);
}

int main()
{
    cout << toggleBit(5, 1);
}