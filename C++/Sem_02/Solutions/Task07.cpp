#include <iostream>
using namespace std;

int main()
{
	double a;
	double b;
	char op;

	cin >> a >> b >> op;

	switch (op)
	{
	case '+': cout << a + b; break;
	case '-': cout << a - b; break;
	case '*': cout << a * b; break;
	case '/': cout << a / b; break;

	default: cout << "Invalid operation!"; break;
	}
}