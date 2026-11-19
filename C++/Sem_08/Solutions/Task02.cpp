#include <iostream>

void findTwoUnique(const int* arr, const int n, int& first, int& second)
{
    unsigned x = 0;
    for (int i = 0; i < n; ++i)
    {
        x ^= (unsigned)arr[i];
    }

    unsigned diff = x & -x; // най-десният бит 1: тук a и b се различават

    unsigned a = 0;
    for (int i = 0; i < n; ++i)
    {
        if ((unsigned)arr[i] & diff)
        {
            a ^= (unsigned)arr[i];  // двойките в групата се унищожават
        }
    }

    first = (int)a;
    second = (int)(x ^ a);
}

int main()
{
    int arr[] = {9, 18, 9, -50, 12, 18, 15, 12, -50, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    int a, b;
    findTwoUnique(arr, n, a, b);
    std::cout << a << ' ' << b << '\n';

    return 0;
}
