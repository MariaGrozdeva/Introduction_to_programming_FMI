#include <iostream>

unsigned myStrlen(const char* str, unsigned res)
{
    if (*str == '\0')
    {
        return res;
    }
    return myStrlen(++str, ++res);
}

unsigned myStrlen(const char* str)
{
    return myStrlen(str, 0);
}

int main()
{
    std::cout << myStrlen("informatika_3");
    return 0;
}
