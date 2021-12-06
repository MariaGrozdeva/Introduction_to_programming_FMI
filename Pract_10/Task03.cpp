#include <iostream>
using namespace std;

void Swap1(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
void Swap2(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int a, b;
	cin >> a >> b;

	cout << "Before swap: a=" << a << ", b=" << b << endl;
	Swap2(&a, &b);
	cout << "After swap: a=" << a << ", b=" << b << endl;
}