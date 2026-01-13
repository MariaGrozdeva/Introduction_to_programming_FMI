#include <iostream>
#include <cmath>

void printBitstring(const bool* bitstring, const size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << bitstring[i];
	}
	std::cout << std::endl;
}

void generateAllBitstringsWithEqualSum(unsigned start, unsigned end, int diff, bool* bitstring, const size_t size)
{
	if (std::abs(diff) > (end - start + 1) / 2)
	{
		return;
	}
	if (start > end && diff == 0)
	{
		printBitstring(bitstring, size);
		return;
	}

	bitstring[start] = bitstring[end] = 0;
	generateAllBitstringsWithEqualSum(start + 1, end - 1, diff, bitstring, size);

	bitstring[start] = bitstring[end] = 1;
	generateAllBitstringsWithEqualSum(start + 1, end - 1, diff, bitstring, size);

	bitstring[start] = 0;
	bitstring[end] = 1;
	generateAllBitstringsWithEqualSum(start + 1, end - 1, diff + 1, bitstring, size);

	bitstring[start] = 1;
	bitstring[end] = 0;
	generateAllBitstringsWithEqualSum(start + 1, end - 1, diff - 1, bitstring, size);
}

void generateAllBitstringsWithEqualSum(size_t n)
{
	bool* bitstring = new bool[2 * n];
	generateAllBitstringsWithEqualSum(0, 2 * n - 1, 0, bitstring, 2 * n);
	
	delete[] bitstring;
}

int main()
{
	size_t n;
	std::cin >> n;

	generateAllBitstringsWithEqualSum(n);
}
