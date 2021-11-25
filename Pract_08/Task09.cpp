#include <iostream>

unsigned strLen(const char str[])
{
	int len = 0;
	while (str[len] != '\0')
		len++;

	return len;
}

bool areTwoWordsSame(const char str1[], const char str2[], unsigned startIdx)
{
	unsigned len1 = strLen(str1);
	unsigned len2 = strLen(str2);
	unsigned newLen = startIdx + len2;
	for (size_t i = startIdx, j = 0; i < newLen; i++, j++)
	{
		if (str1[i] != str2[j])
			return false;
	}

	return true;
}

void replaceWords(char result[], char sentence[], const char toBeReplaced[], const char word[])
{
	unsigned sentenceLen = strLen(sentence);
	unsigned wordLen = strLen(word);
	unsigned toBeReplacedLen = strLen(toBeReplaced);
	int resultIdx = 0;
	for (size_t i = 0; i < sentenceLen; i++)
	{
		if (sentence[i] == toBeReplaced[0] && areTwoWordsSame(sentence, toBeReplaced, i))
		{
			for (size_t j = 0; j < wordLen; j++)
				result[resultIdx++] = word[j];

			i += toBeReplacedLen - 1;	
		}
		else
		{
			result[resultIdx] = sentence[i];
			resultIdx++;
		}
	}

	result[resultIdx] = '\0';
}

int main()
{
	const unsigned maxSizeSentence = 1024;
	const unsigned maxSizeWord = 64;

	char sentence[maxSizeSentence];
	char toBeReplaced[maxSizeWord];
	char word[maxSizeWord];
	char result[maxSizeSentence];

	std::cin.getline(sentence, maxSizeSentence);
	std::cin >> toBeReplaced;
	std::cin >> word;
	
	replaceWords(result, sentence, toBeReplaced, word);
	std::cout << result;


	return 0;
}