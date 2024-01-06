#include <iostream>

void printPartition(const char* bitstring)
{
	std::cout << 1;
	for (size_t i = 0; bitstring[i] != '\0'; i++)
	{
		if (bitstring[i] == '0')
			std::cout << ' ' << i + 2;
		else
			std::cout << std::endl << i + 2;
	}
	std::cout << std::endl << std::endl;
}
void generateAllBitstrings(char* bitstring, size_t len, size_t pos, void(*callBack)(const char*))
{
	if (pos == len)
	{
		bitstring[pos] = '\0';
		callBack(bitstring);
		return;
	}

	bitstring[pos] = '0';
	generateAllBitstrings(bitstring, len, pos + 1, callBack);

	bitstring[pos] = '1';
	generateAllBitstrings(bitstring, len, pos + 1, callBack);
}

void printPartitions(size_t n)
{
	char* bitstring = new char[n]; // bitstring of length n-1 + 1 for '\0'
	generateAllBitstrings(bitstring, n - 1, 0, printPartition);
	
	delete[] bitstring;
}

int main()
{
	size_t n;
	std::cin >> n;

	printPartitions(n);
}