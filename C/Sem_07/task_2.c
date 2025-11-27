#include <stdio.h>
#include <limits.h>

unsigned short countOnes(int number)
{
    unsigned short counter = 0;
    unsigned short size = sizeof(int) * CHAR_BIT;

    for (int i = 0; i < size; i++)
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
    printf("%hd", countOnes(number));
    return 0;
}