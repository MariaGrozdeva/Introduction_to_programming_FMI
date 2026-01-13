#include <iostream>
#include <cstring>
using namespace std;

#pragma warning (disable : 4996)

bool isDigit(char ch)
{
    return ch >= '0' && ch <='9';
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
    bool isPrevDigit = false;
    
    while (*str != '\0')
    {
        bool isCurrentDigit = isDigit(*str);
        if (isCurrentDigit && !isPrevDigit)
        {
            count++;
        }
        str++;
        isPrevDigit = isCurrentDigit;
    }
    
    return count;
}

void moveStrIter(const char* str, unsigned int& strIter)
{
    while (isDigit(str[strIter]))
    {
        strIter++;
    }
}

char* censoreNumbersFromString(const char* str, const char* censorePattern)
{
    if (!str || !censorePattern)
    {
        return nullptr;
    }
    
    const short CENSORE_PATTERN_LEN = strlen(censorePattern);
    
    unsigned int toRemove = countDigitsInString(str);
    unsigned int toAdd = countNumbersInString(str) * CENSORE_PATTERN_LEN;
    
    char* censoredStr = new char[strlen(str) + toAdd - toRemove + 1];
    
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
            censoredStr[censoredStrIter] = '\0';
            strcat(censoredStr, censorePattern);
            censoredStrIter += CENSORE_PATTERN_LEN;
            moveStrIter(str, strIter);
        }
    }
    
    censoredStr[censoredStrIter] = '\0';
    return censoredStr;
}

int main()
{
    char* res = censoreNumbersFromString("test124again4pocket55p", "_NUM_");
    cout << res << endl;
    delete[] res;
}
