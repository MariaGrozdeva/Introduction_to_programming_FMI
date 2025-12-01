#include <stdio.h>
#include <string.h>

#define MAX_SIZE 64

int isValidWordSymbol(const char symbol)
{
    return (symbol >= 'a' && symbol <= 'z') || (symbol >= 'A' && symbol <= 'Z') || (symbol >= '0' && symbol <= '9') || symbol == '_';
}

unsigned int getWordsCount(const char* str)
{
    unsigned int wordsCount = 0;
    int isPrevSymbolValid = 0;
    
    while (*str != '\0')
    {
        int isCurrentSymbolValid = isValidWordSymbol(*str);
        if (isCurrentSymbolValid && !isPrevSymbolValid)
        {
            wordsCount++;
        }
        str++;
        isPrevSymbolValid = isCurrentSymbolValid;
    }
    
    return wordsCount;
}

int main()
{
    char str[MAX_SIZE];
    fgets(str, MAX_SIZE, stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove newline
    printf("%d", getWordsCount(str));
}
