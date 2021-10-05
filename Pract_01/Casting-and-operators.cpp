#include <iostream>
using namespace std;

int main() 
{
	// explicit casting - WITHOUT losing information
	int  int_value = 32;
	char char_value = 'e';
	cout << int   (int_value + char_value) << endl; // output: 133
	cout << float (int_value + char_value) << endl; // output: 133
	cout << char  (int_value + char_value) << endl; // output: 'E'
	cout << bool  (int_value + char_value) << endl; // output: 1

	// implicit casting - WITH losing information
	int  int_value2  = 54;
	char char_value2 = int_value2;
	cout << char_value2 << endl; // output: 6

	double double_value = 67.344;
	int int_value3 = double_value;
	cout << int_value3 << endl;         // output: 67
	cout << (int_value3 + 's') << endl; // output: 182

	char char_value3 = '+';
	bool bool_value  = char_value3;
	cout << bool_value          << endl; // output: 1
	cout << (bool_value + 1)    << endl; // output: 2
	cout << (bool_value + 4.54) << endl; // output: 5.45

	//***************************************************************************************************

	char ch1 = '7';
	char ch2 = 'y';
	int i = 22;

	bool b1 = i >= ch1;
	cout << b1 << endl;               // output: 0

	bool b2 = i % ch2 == 0;
	cout << b2 << endl;               // output: 0

	bool b3 = i / ch2 != 0;
	cout << b3 << endl;               // output: 0

	bool b4 = i + ch1 <= 'a';
	cout << b4 << endl;               // output: 1
	
	bool b5 = ((i + ch1) % 10) >= 10; 
	cout << b5 << endl;               // output: 0
}