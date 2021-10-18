#include <iostream>
using namespace std;

int main()
{
	char letter;
	cin >> letter;

	switch (letter)
	{
	case 'a': cout << "Yes, it's vowel!"; break;
	case 'u': cout << "Yes, it's vowel!"; break;
	case 'e': cout << "Yes, it's vowel!"; break;
	case 'i': cout << "Yes, it's vowel!"; break;
	case 'o': cout << "Yes, it's vowel!"; break;

	default: cout << "No, it's consonant!"; break;
	}
}