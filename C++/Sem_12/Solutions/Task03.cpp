#include <iostream>
#include <climits>
#include <cstddef>

int minElement(const int *arr, std::size_t size, int minEl)
{
    if (size == 0)
    {
        return minEl;
    }

    return minElement(arr + 1, size - 1, (*arr < minEl) ? *arr : minEl);
}

int minElement(const int *arr, std::size_t size)
{
    return minElement(arr, size, INT_MAX);
}

int main()
{
    int arr[] = { 1, 5, -10, -11, 0 };
    std::cout << minElement(arr, 5);
    return 0;
}
