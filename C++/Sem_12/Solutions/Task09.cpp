#include <iostream>

int getNthOccurrence(const char* str, const char symbol, const unsigned n, int pos)
{
    if (n == 0)
    {
        return pos - 1;
    }
    if (*str == '\0')
    {
        return -1;
    }
    if (*str == symbol)
    {
        return getNthOccurrence(str + 1, symbol, n - 1, pos + 1);
    }
    else
    {
        return getNthOccurrence(str + 1, symbol, n, pos + 1);
    }
}

int getNthOccurrence(const char* str, const char symbol, const unsigned n)
{
    return getNthOccurrence(str, symbol, n, 0);
}

int main()
{
    std::cout << getNthOccurrence("abcabca", 'a', 3);
    return 0;
}
