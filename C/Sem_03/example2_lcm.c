#include <stdio.h>

int main()
{
    unsigned n, m;
    do
    {
        scanf("%u %u", &n, &m);
    } while (n == 0 || m == 0);

    unsigned maxNum = n > m ? n : m;
    unsigned lcm = maxNum;

    while (lcm % n != 0 || lcm % m != 0)
    {
        lcm += maxNum;
    }

    printf("%u", lcm);
    return 0;
}
