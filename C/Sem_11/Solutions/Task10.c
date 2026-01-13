#include <stdio.h>
#include <stdlib.h>

void printArray(const unsigned* arr, const unsigned size)
{
    for (int i = 0; i < size; i++)
    {
        i == size - 1 ? printf("%u ", arr[i]) : printf("%u, ", arr[i]);
    }
    printf("\n");
}

void fillTubesHelper(const unsigned m, const unsigned n, unsigned* litresPerTube, unsigned pos)
{
    if (pos == m - 1)
    {
        litresPerTube[pos] = n;
        printArray(litresPerTube, m);
        return;
    }

    for (int i = 0; i <= n; i++)
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

    unsigned* litresPerTube = (unsigned*)malloc(sizeof(unsigned) * m);
    if (!litresPerTube)
    {
        return;
    }

    fillTubesHelper(m, n, litresPerTube, 0);

    free(litresPerTube);
}

int main()
{
    fillTubes(3, 8);
    return 0;
}
