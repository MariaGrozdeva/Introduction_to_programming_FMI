#include <iostream>
using namespace std;

const int maxSize = 32;

void input(char*& str) 
{
	char input[maxSize];
	cin >> input;

	int len = strlen(input);
	str = new char[len + 1];

	strcpy_s(str, len + 1, input);
}
void input(char**& dictionary, int n) 
{
	dictionary = new char* [n];

	for (size_t i = 0; i < n; i++) 
	{
		dictionary[i] = new char[maxSize + 1];
		input(dictionary[i]);
	}
}

void free(char** dictionary, int n) 
{
	for (size_t i = 0; i < n; i++)
		delete[] dictionary[i];
	delete[] dictionary;
}

bool contains(char** const dictionary, int n, const char* word) 
{
	for (size_t i = 0; i < n; i++) 
	{
		if (strcmp(dictionary[i], word) == 0)
			return true;
	}
	return false;
}

int main()
{
	char* word;
	input(word);

	int n;
	cin >> n;

	char** dictionary;
	input(dictionary, n);

	cout << contains(dictionary, n, word);
	
	free(dictionary, n);
}