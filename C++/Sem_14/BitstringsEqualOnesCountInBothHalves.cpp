#include <iostream>
#include <cassert>

void printBitstring(const bool* bitstring, const size_t n)
{
	for (size_t i = 0; i < n; i++)
	{
		std::cout << bitstring[i];
	}
	std::cout << std::endl;
}

void generateAllBitstrings(bool* bitstring, unsigned int pos, const size_t n, bool(*pred)(const bool* bitstring, const size_t n))
{
	if (pos == n)
	{
	    if (pred(bitstring, n))
	    {
		    printBitstring(bitstring, n);
	    }
	    return;
	}

	bitstring[pos] = 0;
	generateAllBitstrings(bitstring, pos + 1, n, pred);

	bitstring[pos] = 1;
	generateAllBitstrings(bitstring, pos + 1, n, pred);
}

void printBitstrings(const size_t n, bool(*pred)(const bool* bitstring, const size_t n))
{
	bool* bitstring = new bool[n];
	generateAllBitstrings(bitstring, 0, n, pred);
	delete[] bitstring;
}

bool hasEqualOnesCountInBothHalves(const bool* bitstring, const size_t n)
{
    assert(n % 2 == 0);
	
    int sum = 0;
    for (size_t i = 0; i < n / 2; i++)
    {
        sum += bitstring[i];
    }
    for (size_t i = n / 2; i < n; i++)
    {
        sum -= bitstring[i];
    }
    return sum == 0;
}

int main()
{
	printBitstrings(4, hasEqualOnesCountInBothHalves);
}
