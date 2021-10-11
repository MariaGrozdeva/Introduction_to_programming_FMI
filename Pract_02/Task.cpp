#include <iostream>
using namespace std;

int main()
{
	int a = 1;
	char ch = 'a';
	bool b;

	int c = 96;
	int d = c++ - ch;

	if (a--)
	{
		cout << "1. a is: " << a++ << endl; // 0
		b = a && ch;
	}
	if (b)
	{
		if (b += a && ch)
		{
			a += ++a;
			cout << "2. a is: " << a << endl; // 4
		}
		if (d + 1) // condition is false
		{
			cout << "3. d is " << d << endl;
		}
		else if ((++d %= 2) == 0)
		{
			cout << "4. d is even" << endl;
		}
		else
		{
			cout << "5. d is odd" << endl;
		}
	}
	if (d)
	{
		cout << "6. d has a nonzero value" << endl;
	}
	else
	{
		cout << "7. d equals zero" << endl;
	}
}