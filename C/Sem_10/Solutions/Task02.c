#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_SIZE 2048
const size_t censorePatternSize = 2;

void freeMemory(char** words, const unsigned wordsCount)
{
	for (size_t i = 0; i < wordsCount; i++)
	{
		free(words[i]);
	}
	free(words);
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

void printWords(char* const* words, const unsigned wordsCount)
{
	for (size_t i = 0; i < wordsCount; i++)
	{
		printf("%s ", words[i]);
	}
	printf("\n");
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

	char* resultText = (char*)malloc(textLength + 1);
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

		words[i] = (char*)malloc(tempWordLen + censorePatternSize + 1);
		strcpyWithGivenSIze(words[i], text, tempWordLen);

		text += (tempWordLen + 1);
	}
}

void changeWordByIndex(char** words, const unsigned wordsCount, const unsigned index, const char* newWord)
{
	assert(index < wordsCount);

	free(words[index]);
	words[index] = (char*)malloc(strlen(newWord) + censorePatternSize + 1);
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
	char buff[MAX_SIZE];
	fgets(buff, MAX_SIZE, stdin);
	buff[strcspn(buff, "\n")] = '\0'; // Remove newline character if present

	size_t wordsCount = getWordsCount(buff);
	char** textArr = (char**)malloc(wordsCount * sizeof(char*));
	fillWordsToArrayOfWords(textArr, wordsCount, buff);

	printf("\nInitial:\n");
	printWords(textArr, wordsCount);

	printf("\nCensore the first word:\n");
	censoreOrDiscensore(textArr, wordsCount, 1);
	printWords(textArr, wordsCount);

	printf("\nCensore the second word:\n");
	censoreOrDiscensore(textArr, wordsCount, 2);
	printWords(textArr, wordsCount);

	printf("\nDiscensore the first word:\n");
	censoreOrDiscensore(textArr, wordsCount, 1);
	printWords(textArr, wordsCount);

	printf("\nChange the first word:\n");
	changeWordByIndex(textArr, wordsCount, 1, "TESTCHANGE");
	printWords(textArr, wordsCount);

	printf("\nFinal:\n");
	char* finalText = extractText(textArr, wordsCount);
	printf("%s\n", finalText);

	free(finalText);
	freeMemory(textArr, wordsCount);
}
