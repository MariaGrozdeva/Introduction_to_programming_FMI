#include <iostream>
using namespace std;

int main() 
{
	int a = 10;
	(++a) += 5;
	cout << a << endl; // a = 16

	int b = 10;
	// (b++) += 5; // ERROR! b++ returns 10 and the expression "10 += 5" is NOT valid!
	cout << b << endl; 

	int c = 10;
	c = (c += 5) + (c += 8); 
	cout << c << endl; // c = 46

	int d = 23;
	// ++d++; // ERROR! The suffix operator ++ is with higher priority than the prefix one, so the expression is same as "++(d++)" = "++24" which is NOT valid! 
	cout << d << endl;

	int e = 33;
	(++e)++;
	cout << e << endl; // e = 35;

	int f = 5;
	f += ++f; // Same as f = f + ++f <=> f = 6 + 6 <=> f = 12
	cout << f << endl; // f = 12
}