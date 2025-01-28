#include <iostream>
using namespace std;

void init(bool* sieve, size_t size, bool value)
{
    for (size_t i = 1; i <= size; i++)
    {
        sieve[i] = value;
    }
}
void printSolution(const bool* sieve, size_t size)
{
    for (size_t i = 1; i <= size; i++)
    {
        if (sieve[i])
        {
            cout << i << ' ';
        }
    }
}

void markNotNeededNumbers(bool* sieve, size_t size, unsigned int queryNumber)
{
    for (size_t i = 1; i <= size; i++)
    {
        if ((i % queryNumber == 0) || (queryNumber % i == 0))
        {
            sieve[i] = false;
        }
    }
}

int main()
{
    const size_t MAX_SIZE = 1024;
    bool sieve[MAX_SIZE];

    unsigned int n;
    cin >> n;
    init(sieve, n, true);

    unsigned int userQuery;
    cin >> userQuery;
    while (userQuery != 0)
    {
        markNotNeededNumbers(sieve, n, userQuery);
        cin >> userQuery;
    }

    printSolution(sieve, n);
}