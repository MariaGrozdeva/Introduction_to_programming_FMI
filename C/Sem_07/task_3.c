#include <stdio.h>
#include <limits.h>

unsigned short turnRightMostBitOne(int number)
{
    for (int i = 0; i < sizeof(int) * CHAR_BIT; i++)
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