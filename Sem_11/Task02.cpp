#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;

#pragma warning (disable : 4996)

const size_t censorePatternSize = 2;

void free(char** words, const unsigned wordsCount)
{
	for (size_t i = 0; i < wordsCount; i++)
	{
		delete[] words[i];
	}
	delete[] words;
}

unsigned getWordsCount(const char* text)
{
	unsigned count = 0;
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

void printWords(const char* const* words, const unsigned wordsCount)
{
	for (size_t i = 0; i < wordsCount; i++)
	{
		cout << words[i] << ' ';
	}
	cout << endl;
}

void strcpyWithGivenSIze(char* dest, const char* src, const size_t srcSize)
{
	for (size_t i = 0; i < srcSize; i++)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
}

size_t strlenToSpace(const char* text)
{
	if (!text)
    	{
        	return 0;
    	}
    
	size_t length = 0;
	while (*text != '\0' && *text != ' ')
	{
		length++;
		text++;
	}
	return length;
}

char* extractText(char** words, const unsigned wordsCount)
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

void fillWordsToArrayOfWords(char** words, const unsigned wordsCount, const char* text)
{
	for (size_t i = 0; i < wordsCount; i++)
	{
		size_t tempWordLen = strlenToSpace(text);

		words[i] = new char[tempWordLen + censorePatternSize + 1];
		strcpyWithGivenSIze(words[i], text, tempWordLen);

		text += (tempWordLen + 1);
	}
}

void changeWordByIndex(char** words, const unsigned wordsCount, const unsigned index, const char* newWord)
{
    	assert(index < wordsCount);
    
	delete[] words[index];
	words[index] = new char[strlen(newWord) + censorePatternSize + 1];
	strcpy(words[index], newWord);
}

void censoreOrDiscensore(char** words, const unsigned wordsCount, const unsigned index)
{
    	assert(index < wordsCount);
    
	if (strcmp(words[index], "*") == 0)
	{
		strcpy(words[index], words[index] + censorePatternSize);
	}
	else
	{
		size_t wordLength = strlen(words[index]);
		for (int i = wordLength; i >= 0; i--) // shifting so we have the original word saved (in case of discensore)
		{
			words[index][i + censorePatternSize] = words[index][i];
		}
		words[index][0] = '*';
		words[index][1] = '\0';
	}
}

int main()
{
    	constexpr size_t MAX_SIZE = 2048;
	char buff[MAX_SIZE];
	cin.getline(buff, MAX_SIZE);

	size_t wordsCount = getWordsCount(buff);
	char** textArr = new char*[wordsCount];
	fillWordsToArrayOfWords(textArr, wordsCount, buff);

    	cout << endl << "Initial:" << endl;
	printWords(textArr, wordsCount);

	cout << endl << "Censore the first word:" << endl;
	censoreOrDiscensore(textArr, wordsCount, 1);
	printWords(textArr, wordsCount);

	cout << endl << "Censore the second word:" << endl;
	censoreOrDiscensore(textArr, wordsCount, 2);
	printWords(textArr, wordsCount);

	cout << endl << "Discensore the first word:" << endl;
	censoreOrDiscensore(textArr, wordsCount, 1);
	printWords(textArr, wordsCount);

	cout << endl << "Change the first word:" << endl;
	changeWordByIndex(textArr, wordsCount, 1, "TESTCHANGE");
	printWords(textArr, wordsCount);

	cout << endl << "Final:" << endl;
	char* finalText = extractText(textArr, wordsCount);
	cout << finalText << endl;
	
	delete[] finalText;
	free(textArr, wordsCount);
}
