#include <stdio.h>

unsigned short turnRightMostBitOne(int number)
{
    for (int i = 0; i < 32; i++)
    {
        if (number & (1 << i))
        {
            number = number & ~(1 << i);
            break;
        }
    }

    return number;
}

int main()
{
    int number = 0;
    scanf("%d", &number);
    printf("%hd", turnRightMostBitOne(number));
    return 0;
}