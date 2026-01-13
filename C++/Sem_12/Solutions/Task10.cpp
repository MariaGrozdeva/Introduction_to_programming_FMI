#include <iostream>
#include <new>

void printArray(const unsigned* arr, const unsigned size)
{
    for (int i = 0; i < size; i++)
    {
        i == size - 1 ? std::cout << arr[i] << " " : std::cout << arr[i] << ", ";
    }
    std::cout << "\n";
}

void fillTubesHelper(const unsigned m, const unsigned n, unsigned* litresPerTube, unsigned pos)
{
    if (pos == m - 1)
    {
        litresPerTube[pos] = n;
        printArray(litresPerTube, m);
        return;
    }

    for (int i = 0; i <= (int)n; i++)
    {
        litresPerTube[pos] = i;
        fillTubesHelper(m, n - i, litresPerTube, pos + 1);
    }
}

void fillTubes(const unsigned m, const unsigned n)
{
    if (m == 0)
    {
        return;
    }

    unsigned* litresPerTube = new (std::nothrow) unsigned[m];
    if (!litresPerTube)
    {
        return;
    }

    fillTubesHelper(m, n, litresPerTube, 0);

    delete[] litresPerTube;
}

int main()
{
    fillTubes(3, 8);
    return 0;
}
