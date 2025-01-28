#include <iostream>

void towerOfHanoi(unsigned int n, char a, char b, char c)
{
    if (n == 0)
    {
        return;
    }
    
    towerOfHanoi(n - 1, a, c, b);
    std::cout << "Moved disk from " << a << " to " << c << std::endl;
    towerOfHanoi(n - 1, b, a, c);
}

int main()
{
    unsigned int n = 3;
    char a = 'A', b = 'B', c = 'C';
    
    towerOfHanoi(n, a, b, c);
}
