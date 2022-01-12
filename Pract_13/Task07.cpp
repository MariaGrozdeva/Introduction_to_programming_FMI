#include <iostream>

const int MAX = 32;

void input(char*& word)
{
	char input[MAX];
	std::cin >> input;
	
	int len = strlen(input);
	word = new char[len + 1];

	strcpy_s(word, len + 1, input);
}

void freeWord(char*& word)
{
	delete[] word;
}

void input(char**& dictionary, int numberOfWords)
{
	dictionary = new char* [numberOfWords];
	for (int i = 0; i < numberOfWords; i++)
	{
		dictionary[i] = new char[MAX + 1];
		std::cin >> dictionary[i];
	}
}

void freeDictionary(char** dictionary, int numberOfWords)
{
	for (int i = 0; i < numberOfWords; i++)
		delete[] dictionary[i];
	delete[] dictionary;
}

bool contains(char** const dictionary, int numberOfWords, const char* word)
{
	for (int i = 0; i < numberOfWords; i++)
	{
		if (strcmp(dictionary[i], word) == 0)
			return true;
	}
	return false;
}

int main()
{
	char* word;
	std::cout << "Input the word to be found: ";
	input(word);
	
	int numberOfWords;
	std::cout << "Input number of words in the dictionary: ";
	std::cin >> numberOfWords;
	char** dictionary;
	std::cout << "Input the words in the dictionary: ";
	input(dictionary, numberOfWords);

	std::cout << (contains(dictionary, numberOfWords, word) ? "Yes" : "No");

	freeDictionary(dictionary, numberOfWords);
	freeWord(word);

	return 0;
}