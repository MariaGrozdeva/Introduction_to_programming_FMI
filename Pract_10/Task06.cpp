#include <iostream>
using namespace std;

int strLen(const char* str)
{
	int len = 0;
	while (*str != '\0')
	{
		str++;
		len++;
	}
	return len;
}

void removeSomeElements(char* str, int idxFrom, int numberOfElementsToRemove)
{
	int len = strLen(str);
	if (len < idxFrom || len < idxFrom + numberOfElementsToRemove)
		return;

	for (int i = idxFrom; i < len - 1; i++)
		str[i] = str[i + numberOfElementsToRemove];

	str[len - 1] = '\0';
}

void RLE(char* str)
{
	const int minRepeatedLetters = 4;
	const int numbersOfStringToBeReplaced = 4; // E.g. (5d) has 4 symbols
	
	int len = strLen(str);
	int cnt = 0;
	int endIdx = 0;

	for (int i = 0; i < len; i++)
	{
		cnt = 1;
		while (i < len - 1 && str[i] == str[i + 1])
		{
			i++;
			cnt++;
			endIdx++;
		}
		
		if (cnt >= minRepeatedLetters)
		{
			char letter = str[i];

			str[i - cnt + 1] = '(';
			str[i - cnt + 2] = char(cnt + '0');
			str[i - cnt + 3] = letter;
			str[i - cnt + 4] = ')';
			
			if (cnt > minRepeatedLetters)
			{
				int removeUselessLetters = cnt - minRepeatedLetters;
				int removeFrom = i - cnt + numbersOfStringToBeReplaced + 1;
				
				removeSomeElements(str, removeFrom, removeUselessLetters);
				
				i--;
				len--;
			}
		}
	}
}

int main()
{
	char str[] = "abcdddddaaaaaaabccdddzzzz";
	RLE(str);
	cout << str;
}
