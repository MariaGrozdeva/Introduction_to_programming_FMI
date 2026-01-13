#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isDigit(char ch)
{
    return ch >= '0' && ch <= '9';
}

unsigned int getDigitsCount(const char* str)
{
    unsigned int digitsCount = 0;
    while (*str != '\0')
    {
        if (isDigit(*str))
        {
            digitsCount++;
        }
        str++;
    }
    return digitsCount;
}

void removeDigits(const char* str, char** result)
{
    size_t strLen = strlen(str);
    *result = (char*)malloc((strLen - getDigitsCount(str) + 1) * sizeof(char));

    if (!*result)
    {
        perror("Failed to allocate memory");
        return;
    }

    unsigned int newStrIter = 0;
    for (size_t i = 0; i < strLen; i++)
    {
        if (!isDigit(str[i]))
        {
            (*result)[newStrIter++] = str[i];
        }
    }
    (*result)[newStrIter] = '\0';
}

int main()
{
    const size_t MAX_SIZE = 128;

    char str[MAX_SIZE + 1];
    printf("Enter a string: \n");
    fgets(str, MAX_SIZE, stdin);

    // Remove trailing newline character from fgets
    str[strcspn(str, "\n")] = '\0';

    char* result = NULL;
    removeDigits(str, &result);

    printf("String without digits: %s\n", result);

    free(result);
    return 0;
}
