#include <iostream>
using namespace std;

void printSubsets(const int *arr, const size_t size)
{
    int total = 1 << size;
    cout << "[], ";
    for (int mask = 1; mask < total; mask++)
    {
        int first = 1;
        cout << "[";
        for (int i = 0; i < (int)size; i++)
        {
            if ((mask >> i) & 1)
            {
                if (!first)
                    cout << ",";
                cout << arr[i];
                first = 0;
            }
        }
        cout << "], ";
    }
}

void readArray(int *arr, const size_t size)
{
    for (int i = 0; i < (int)size; i++)
    {
        cin >> arr[i];
    }
}

int main()
{
    constexpr int CAP = 3;

    int arr[CAP] = {0};
    const size_t size = sizeof(arr) / sizeof(int);
    readArray(arr, size);
    printSubsets(arr, size);

    return 0;
}

