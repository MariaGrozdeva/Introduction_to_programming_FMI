#include <iostream>
using namespace std;

const int MAX = 32;

void input(char*& word)
{
	char input[MAX];
	cin >> input;
	
	int len = strlen(input);
	word = new char[len + 1];

	strcpy_s(word, len + 1, input);
}
void freeWord(char* word)
{
	delete[] word;
}

void input(char**& dictionary, int numberOfWords)
{
	dictionary = new char* [numberOfWords];
	for (size_t i = 0; i < numberOfWords; i++)
	{
		dictionary[i] = new char[MAX + 1];
		cin >> dictionary[i];
	}
}
void freeDictionary(char** dictionary, int numberOfWords)
{
	for (size_t i = 0; i < numberOfWords; i++)
		delete[] dictionary[i];
	delete[] dictionary;
}

bool contains(char** const dictionary, int numberOfWords, const char* word)
{
	for (size_t i = 0; i < numberOfWords; i++)
	{
		if (strcmp(dictionary[i], word) == 0)
			return true;
	}
	return false;
}

int main()
{
	char* word;
	cout << "Input the word to be found: ";
	input(word);
	
	int numberOfWords;
	cout << "Input number of words in the dictionary: ";
	cin >> numberOfWords;
	
	char** dictionary;
	cout << "Input the words in the dictionary: " << endl;
	input(dictionary, numberOfWords);

	cout << contains(dictionary, numberOfWords, word) ? "Yes" : "No";

	freeDictionary(dictionary, numberOfWords);
	freeWord(word);
}
