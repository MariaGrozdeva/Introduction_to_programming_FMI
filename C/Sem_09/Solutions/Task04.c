#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isUppercase(char ch)
{
    return ch >= 'A' && ch <= 'Z';
}

int isLowercase(char ch)
{
    return ch >= 'a' && ch <= 'z';
}

void getUppercaseAndLowercaseCount(const char* str, unsigned int* uppercaseCount, unsigned int* lowercaseCount)
{
    while (*str != '\0')
    {
        if (isUppercase(*str))
        {
            (*uppercaseCount)++;
        }
        else if (isLowercase(*str))
        {
            (*lowercaseCount)++;
        }
        str++;
    }
}

void getUppercaseStrAndLowercaseStr(const char* str, char** uppercaseStr, char** lowercaseStr)
{
    if (!str)
    {
        return;
    }

    unsigned int uppercaseCount = 0;
    unsigned int lowercaseCount = 0;

    getUppercaseAndLowercaseCount(str, &uppercaseCount, &lowercaseCount);

    *uppercaseStr = (char*)malloc((uppercaseCount + 1) * sizeof(char));
    *lowercaseStr = (char*)malloc((lowercaseCount + 1) * sizeof(char));

    if (!*uppercaseStr || !*lowercaseStr)
    {
        perror("Failed to allocate memory");
        return;
    }

    unsigned int uppercaseStrIter = 0;
    unsigned int lowercaseStrIter = 0;

    while (*str != '\0')
    {
        if (isUppercase(*str))
        {
            (*uppercaseStr)[uppercaseStrIter++] = *str;
        }
        else if (isLowercase(*str))
        {
            (*lowercaseStr)[lowercaseStrIter++] = *str;
        }
        str++;
    }
    (*uppercaseStr)[uppercaseStrIter] = '\0';
    (*lowercaseStr)[lowercaseStrIter] = '\0';
}

int main()
{
    const size_t MAX_SIZE = 256;

    char str[MAX_SIZE + 1];
    printf("Enter a string: \n");
    fgets(str, MAX_SIZE, stdin);

    // Remove trailing newline character from fgets
    str[strcspn(str, "\n")] = '\0';

    char* uppercaseStr = NULL;
    char* lowercaseStr = NULL;

    getUppercaseStrAndLowercaseStr(str, &uppercaseStr, &lowercaseStr);

    printf("Uppercase characters: %s\n", uppercaseStr);
    printf("Lowercase characters: %s\n", lowercaseStr);

    free(uppercaseStr);
    free(lowercaseStr);

    return 0;
}
