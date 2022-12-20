#include <iostream>
using namespace std;

#pragma warning (disable : 4996)

void printWords(char** words, unsigned int wordsCount)
{
	for (size_t i = 0; i < wordsCount; i++)
	{
		cout << words[i] << ' ';
	}
	cout << endl;
}

void free(char** words, unsigned int wordsCount)
{
	for (size_t i = 0; i < wordsCount; i++)
	{
		delete[] words[i];
	}
	delete[] words;
}

void myStrcpy(char* dest, const char* src, size_t srcSize)
{
	for (size_t i = 0; i < srcSize; i++)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
}

size_t myStrlen(const char* text)
{
	unsigned int length = 0;
	while (*text != '\0' && *text != ' ')
	{
		length++;
		text++;
	}
	return length;
}

unsigned int getWordsCount(const char* text)
{
	unsigned int count = 0;
	while (*text)
	{
		if (*text == ' ')
		{
			count++;
		}
		text++;
	}
	return count + 1;
}

char* extractText(char** words, unsigned int wordsCount)
{
	size_t textLength = 0;
	for (size_t i = 0; i < wordsCount; i++)
	{
		textLength += strlen(words[i]);
	}
	textLength += (wordsCount - 1); // for spaces

	char* resultText = new char[textLength + 1];
	resultText[0] = '\0'; // for the first strcat to work

	for (size_t i = 0; i < wordsCount; i++)
	{
		strcat(resultText, words[i]);
		if (i != wordsCount - 1)
		{
			strcat(resultText, " ");
		}
	}

	return resultText;
}

void fillWordsToArrayOfWords(char** words, const char* text, unsigned int wordsCount)
{
	for (size_t i = 0; i < wordsCount; i++)
	{
		size_t tempWordLen = myStrlen(text);

		words[i] = new char[tempWordLen + 3];
		myStrcpy(words[i], text, tempWordLen);

		text += (tempWordLen + 1);
	}
}

void changeWordByIndex(char** words, unsigned int index, const char* newWord)
{
	delete[] words[index];
	words[index] = new char[strlen(newWord) + 3];
	strcpy(words[index], newWord);
}

void censoreOrDiscensore(char** words, unsigned int index)
{
	if (strcmp(words[index], "*") == 0)
	{
		strcpy(words[index], words[index] + 2);
	}
	else
	{
		size_t wordLength = strlen(words[index]);
		for (int i = wordLength; i >= 0; i--) // shifting so we have the original word saved (in case of discensore)
		{
			words[index][i + 2] = words[index][i];
		}
		words[index][0] = '*';
		words[index][1] = '\0';
	}
}

int main()
{

}