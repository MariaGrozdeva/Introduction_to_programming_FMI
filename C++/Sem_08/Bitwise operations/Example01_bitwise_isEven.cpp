#include <iostream>
using namespace std;

bool isEven(unsigned int n)
{
	return !(n & 1);
}

int main()
{
	cout << isEven(23) << endl;
}