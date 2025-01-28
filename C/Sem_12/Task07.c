#include <stdio.h>

void towerOfHanoi(unsigned int n, char a, char b, char c)
{
    if (n == 0)
    {
        return;
    }
    
    towerOfHanoi(n - 1, a, c, b);
    printf("Moved disk from %c to %c\n", a, c);
    towerOfHanoi(n - 1, b, a, c);
}

int main()
{
    unsigned int n = 3;
    char a = 'A', b = 'B', c = 'C';
    
    towerOfHanoi(n, a, b, c);
    return 0;
}
