#include <iostream>
using namespace std;

int main()
{
	int a = 5;
	int b = 10;

	// int& ref; // ERROR! A reference cannot be declared without being defined.
	int* ptr; // A pointer could have only declaration (without definition).

	int& ref = a;
	ref = b; // DOESN'T reinitialise ref!! The value of ref/a becomes the value of b (10).

	ptr = &a;
	ptr = &b; // Reinitialises ptr!! The value of ptr becomes the address of b.

	ptr = nullptr; // Pointers have a neutral value.
	// References do not!
	ptr = &b;

	// int& ref2 = 5; // ERROR! "Initial value of reference must be an LVALUE" (modifiable)!
	// int* ptr2 = &10; // ERROR! "Expression must be an LVALUE"!

	cout << ref << endl; // value of ref/a (10)
	cout << ptr << endl; // address of b
	cout << *ptr << endl; // value of b (10)
	cout << &ptr << endl; // address ot ptr
}