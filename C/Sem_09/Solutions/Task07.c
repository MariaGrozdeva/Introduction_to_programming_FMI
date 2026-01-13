#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isDigit(char ch)
{
    return ch >= '0' && ch <= '9';
}

unsigned int countDigitsInString(const char* str)
{
    unsigned int count = 0;
    while (*str != '\0')
    {
        if (isDigit(*str))
        {
            count++;
        }
        str++;
    }
    return count;
}

unsigned int countNumbersInString(const char* str)
{
    unsigned int count = 0;
    int isPrevDigit = 0;

    while (*str != '\0')
    {
        int isCurrentDigit = isDigit(*str);
        if (isCurrentDigit && !isPrevDigit)
        {
            count++;
        }
        str++;
        isPrevDigit = isCurrentDigit;
    }

    return count;
}

void moveStrIter(const char* str, unsigned int* strIter)
{
    while (isDigit(str[*strIter]))
    {
        (*strIter)++;
    }
}

char* censoreNumbersFromString(const char* str, const char* censorePattern)
{
    if (!str || !censorePattern)
    {
        return NULL;
    }

    const short CENSORE_PATTERN_LEN = strlen(censorePattern);

    unsigned int toRemove = countDigitsInString(str);
    unsigned int toAdd = countNumbersInString(str) * CENSORE_PATTERN_LEN;

    char* censoredStr = (char*)malloc(strlen(str) + toAdd - toRemove + 1);
    if (!censoredStr)
    {
        perror("Failed to allocate memory");
        return;
    }

    unsigned int strIter = 0;
    unsigned int censoredStrIter = 0;

    while (str[strIter] != '\0')
    {
        if (!isDigit(str[strIter]))
        {
            censoredStr[censoredStrIter++] = str[strIter++];
        }
        else
        {
            strcat(censoredStr + censoredStrIter, censorePattern);
            censoredStrIter += CENSORE_PATTERN_LEN;
            moveStrIter(str, &strIter);
        }
    }

    censoredStr[censoredStrIter] = '\0';
    return censoredStr;
}

int main()
{
    char* res = censoreNumbersFromString("test124again4pocket55p", "_NUM_");
    if (res)
    {
        printf("%s\n", res);
        free(res);
    }
    return 0;
}
