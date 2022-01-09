#include <iostream>
using namespace std;

bool isPrefix(const char text[], const char prefix[])
{
	int i = 0;
	while (prefix[i] != '\0')
	{
		if (text[i] == '\0' || text[i] != prefix[i])
			return false;
		i++;
	}
	return true;
}

void resize(char text[], int size, int newWordLen)
{
	int textLen = strlen(text);
	if (size < 0)
	{
		int absSize = abs(size);
		for (int i = newWordLen; i < textLen - absSize; i++)
			text[i] = text[i + absSize];

		text[textLen - absSize] = '\0';
	}
	else
	{
		for (int i = textLen + size; i > newWordLen - 1; i--)
			text[i] = text[i - size];

		text[textLen + size] = '\0';
	}
}

void replaceSingleWordInBeggining(char text[], const char newWord[], int newWordLen)
{
	int newWordIter = 0;
	for (int i = 0; i < newWordLen; i++)
		text[i] = newWord[newWordIter++];
}

// We suppose that there is enough space in text.
void replace(char text[], const char wordToBeReplaced[], const char newWord[])
{
	char* textIter = text;

	int wordToBeReplacedLen = strlen(wordToBeReplaced);
	int newWordLen = strlen(newWord);
	int differenceInSize = newWordLen - wordToBeReplacedLen;

	while (*textIter != '\0')
	{
		if (isPrefix(textIter, wordToBeReplaced))
		{
			resize(textIter, differenceInSize, newWordLen);
			replaceSingleWordInBeggining(textIter, newWord, newWordLen);
		}
		else
			textIter++;
	}
}

int main()
{
	const int maxTextSize = 1024;
	const int maxWordSize = 32;

	char text[maxTextSize];
	cin.getline(text, maxTextSize);

	char wordToBeReplaced[maxWordSize];
	char newWord[maxWordSize];
	cin >> wordToBeReplaced;
	cin >> newWord;

	replace(text, wordToBeReplaced, newWord);
	cout << text;
}