#include <iostream>

unsigned longestRun(const char* str, char prev, unsigned cur, unsigned best)
{
    if (*str == '\0')
    {
        return best;
    }

    cur = (*str == prev) ? (cur + 1) : 1;
    best = (cur > best) ? cur : best;

    return longestRun(str + 1, *str, cur, best);
}

unsigned longestRun(const char* str)
{
    if (*str == '\0')
    {
        return 0;
    }
    return longestRun(str + 1, *str, 1, 1);
}

int main()
{
    std::cout << longestRun("aaabbbbccccc");
    return 0;
}

