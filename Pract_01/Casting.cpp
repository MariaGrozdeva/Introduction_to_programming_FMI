#include <iostream>
using namespace std;

int main()
{
	int a1 = 97;
	double b1 = a1;
	char c1 = a1;
	bool d1 = a1;

	cout << a1 << endl; // 97
	cout << b1 << endl; // 97.0
	cout << c1 << endl; // a
	cout << d1 << endl; // 1


	double b2 = 65.5;
	int a2 = b2;
	char c2 = b2;
	bool d2 = b2;

	cout << b2 << endl; // 65.5
	cout << a2 << endl; // 65
	cout << c2 << endl; // A
	cout << d2 << endl; // 1


	char c3 = 'a';
	double b3 = c3;
	int a3 = c3;
	bool d3 = c3;

	cout << c3 << endl; // a
	cout << b3 << endl; // 97
	cout << a3 << endl; // 97
	cout << d3 << endl; // 1


	bool d4 = true;
	int a4 = d4;
	double b4 = d4;
	char c4 = d4;

	cout << d4 << endl; // 1
	cout << a4 << endl; // 1
	cout << b4 << endl; // 1
	cout << c4 << endl; // ??
}