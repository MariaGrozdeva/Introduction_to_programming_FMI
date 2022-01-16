#include <iostream>
using namespace std;

void print(const int* bitstring, int len)
{
	for (size_t i = 0; i < len; i++)
		cout << bitstring[i];
	cout << endl;
}
void generateAllBitstringsWithEqualSum(int start, int end, int diff, int* currentBitstring, int len)
{
	if (abs(diff) > (end - start + 1) / 2)
		return;

	if (start > end && diff == 0)
	{
		print(currentBitstring, len);
		return;
	}
	currentBitstring[start] = currentBitstring[end] = 0;
	generateAllBitstringsWithEqualSum(start + 1, end - 1, diff, currentBitstring, len);

	currentBitstring[start] = currentBitstring[end] = 1;
	generateAllBitstringsWithEqualSum(start + 1, end - 1, diff, currentBitstring, len);

	currentBitstring[start] = 0;
	currentBitstring[end] = 1;
	generateAllBitstringsWithEqualSum(start + 1, end - 1, diff + 1, currentBitstring, len);

	currentBitstring[start] = 1;
	currentBitstring[end] = 0;
	generateAllBitstringsWithEqualSum(start + 1, end - 1, diff - 1, currentBitstring, len);
}
void generateAllBitstringsWithEqualSum(int n)
{
	int* currentBitstring = new int[2 * n];
	generateAllBitstringsWithEqualSum(0, 2 * n - 1, 0, currentBitstring, 2 * n);

	delete[] currentBitstring;
}

int main()
{
	int n;
	cin >> n;

	generateAllBitstringsWithEqualSum(n);
}