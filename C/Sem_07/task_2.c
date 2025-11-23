#include <stdio.h>

unsigned short turnRightestBitOne(int number)
{
    unsigned short counter = 0;
    for (int i = 0; i < 32; i++)
    {
        if (number & (1 << i))
        {
            counter++;
        }
    }

    return counter;
}

int main()
{
    int number = 0;
    scanf("%d", &number);
    printf("%hd", turnRightestBitOne(number));
    return 0;
}