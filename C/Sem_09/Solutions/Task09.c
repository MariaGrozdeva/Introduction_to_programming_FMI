#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isDigit(char ch)
{
    return ch >= '0' && ch <= '9';
}

short getDigitsCount(unsigned int num)
{
    short count = 0;
    while (num)
    {
        count++;
        num /= 10;
    }
    return count;
}

int containsNinesOnly(const char** str)
{
    const char* temp = *str;
    while (*temp && isDigit(*temp))
    {
        if (*temp != '9')
        {
            return 0;
        }
        temp++;
    }
    *str = temp;
    return 1;
}

unsigned int getNumsWithNinesOnlyCount(const char* str)
{
    unsigned int count = 0;
    while (*str)
    {
        if (*str == '9')
        {
            const char* temp = str + 1;
            if (containsNinesOnly(&temp))
            {
                count++;
            }
        }
        str++;
    }
    return count;
}

unsigned int stringToNumber(const char** str)
{
    unsigned int number = 0;
    while (**str && isDigit(**str))
    {
        number = number * 10 + (**str - '0');
        (*str)++;
    }
    return number;
}

char* numberToString(unsigned int number)
{
    short digitsCount = getDigitsCount(number);
    char* res = (char*)malloc(digitsCount + 1);
    if (!res)
    {
        perror("Failed to allocate memory");
        return;
    }
    for (int i = digitsCount - 1; i >= 0; i--)
    {
        res[i] = (number % 10) + '0';
        number /= 10;
    }
    res[digitsCount] = '\0';
    return res;
}

char* incrementEachNumber(const char* str)
{
    unsigned int numsWithNinesOnlyCount = getNumsWithNinesOnlyCount(str);
    char* resultStr = (char*)malloc(strlen(str) + numsWithNinesOnlyCount + 1);
    if (!resultStr)
    {
        perror("Failed to allocate memory");
        return;
    }
    resultStr[0] = '\0';

    while (*str)
    {
        if (!isDigit(*str))
        {
            size_t len = strlen(resultStr);
            resultStr[len] = *str;
            resultStr[len + 1] = '\0';
            str++;
        }
        else
        {
            unsigned int incrementedNumber = stringToNumber(&str) + 1;
            char* incrementedNumberAsString = numberToString(incrementedNumber);
            strcat(resultStr, incrementedNumberAsString);
            free(incrementedNumberAsString);
        }
    }

    return resultStr;
}

int main()
{
    const size_t MAX_SIZE = 1024;
    char str[MAX_SIZE + 1];
    if (!fgets(str, MAX_SIZE, stdin))
    {
        perror("Failed to read input");
        return 1;
    }
    // Remove trailing newline if present
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
    {
        str[len - 1] = '\0';
    }

    char* result = incrementEachNumber(str);
    printf("%s\n", result);

    free(result);
    return 0;
}
