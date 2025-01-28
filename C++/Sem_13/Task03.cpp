#include <iostream>

void printBitstring(const bool* bitstring, const unsigned int* set, const size_t size)
{
	std::cout << "{ ";
	for (size_t i = 0; i < size; i++)
	{
		if (bitstring[i])
		{
			std::cout << set[i] << ' ';
		}
	}
	std::cout << "}" << std::endl;
}

void generateAllSubsets(bool* bitstring, unsigned int pos, const size_t size, const unsigned* set)
{
	if (pos == size)
	{
		printBitstring(bitstring, set, size);
		return;
	}

	bitstring[pos] = 0;
	generateAllSubsets(bitstring, pos + 1, size, set);

	bitstring[pos] = 1;
	generateAllSubsets(bitstring, pos + 1, size, set);
}

void printSubsets(const unsigned int* set, const size_t size)
{
	bool* bitstring = new bool[size];
	generateAllSubsets(bitstring, 0, size, set);
	delete[] bitstring;
}

int main()
{
	unsigned int arr[] = { 1, 2, 3, 4 };
	printSubsets(arr, sizeof(arr) / sizeof(unsigned int));
}
