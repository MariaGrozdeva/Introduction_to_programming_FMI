#include <iostream>
#include <algorithm>
#include <climits>

unsigned int getMinimumOperations(unsigned int n)
{
    if (n == 1)
    {
        return 0;
    }
    if (n == 2 || n  == 3)
    {
        return 1;
    }
    
    unsigned int v1 = n % 3 == 0 ? getMinimumOperations(n / 3) : UINT_MAX;
    unsigned int v2 = n % 2 == 0 ? getMinimumOperations(n / 2) : UINT_MAX;
    unsigned int v3 = getMinimumOperations(n - 1);
    
    return 1 + std::min({ v1, v2, v3 });
}

int main()
{
    std::cout << "The minimum number of operations is " << getMinimumOperations(117) << std::endl;
}
