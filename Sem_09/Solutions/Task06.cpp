#include <iostream>
#include <cstring>
using namespace std;

bool isValidWordSymbol(const char symbol)
{
    return (symbol >= 'a' && symbol <= 'z') || (symbol >= 'A' && symbol <= 'Z') || (symbol >= '0' && symbol <= '9') || symbol == '_';
}

unsigned int getWordsCount(const char* str)
{
    unsigned int wordsCount = 0;
    bool isPrevSymbolValid = false;
    
    while (*str != '\0')
    {
        bool isCurrentSymbolValid = isValidWordSymbol(*str);
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
    constexpr size_t MAX_SIZE = 64;

    char str[MAX_SIZE];
    cin.getline(str, MAX_SIZE);

    cout << getWordsCount(str);
}
