#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_SIZE 1024
#define MAX_WORD_SIZE 32

int isPrefix(const char* pattern, const char* str)
{
	while (*pattern != '\0' && *str != '\0')
	{
		if (*pattern != *str)
		{
			return 0;
		}
		pattern++;
		str++;
	}

	return *pattern == '\0';
}

void resize(char* text, int size, const size_t newWordLen)
{
	size_t textLen = strlen(text);
	if (size < 0)
	{
		size_t absSize = abs(size);
		for (size_t i = newWordLen; i < textLen - absSize; i++)
		{
			text[i] = text[i + absSize];
		}
		text[textLen - absSize] = '\0';
	}
	else
	{
		for (int i = textLen + size; i > newWordLen - 1; i--)
		{
			text[i] = text[i - size];
		}
		text[textLen + size] = '\0';
	}
}

void replaceSingleWordInBeggining(char* text, const char* newWord, const size_t newWordLen)
{
	unsigned int newWordIter = 0;
	for (size_t i = 0; i < newWordLen; i++)
	{
		text[i] = newWord[newWordIter++];
	}
}

// We suppose that there is enough space in text.
void replace(char* text, const char* wordToBeReplaced, const char* newWord)
{
	char* textIter = text;

	size_t wordToBeReplacedLen = strlen(wordToBeReplaced);
	size_t newWordLen = strlen(newWord);
	int differenceInSize = newWordLen - wordToBeReplacedLen;

	while (*textIter != '\0')
	{
		if (isPrefix(wordToBeReplaced, textIter))
		{
			resize(textIter, differenceInSize, newWordLen);
			replaceSingleWordInBeggining(textIter, newWord, newWordLen);
		}
		else
		{
			textIter++;
		}
	}
}

int main()
{
        char text[MAX_TEXT_SIZE];
        fgets(text, MAX_TEXT_SIZE, stdin);
        text[strcspn(text, "\n")] = '\0'; // Remove newline

        char wordToBeReplaced[MAX_WORD_SIZE];
        fgets(wordToBeReplaced, MAX_WORD_SIZE, stdin);
        wordToBeReplaced[strcspn(wordToBeReplaced, "\n")] = '\0'; // Remove newline

        char newWord[MAX_WORD_SIZE];
        fgets(newWord, MAX_WORD_SIZE, stdin);
        newWord[strcspn(newWord, "\n")] = '\0'; // Remove newline

        replace(text, wordToBeReplaced, newWord);
        fputs(text, stdout);
}
