#include <iostream>

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

void removeAt(char* str, int pos)
{
	int len = strLen(str);
	for (int i = pos; i < len - 1; i++)
		str[i] = str[i + 1];

	str[len - 1] = '\0';
}

void removeFromTo(char* str, int start, int end)
{
	for (int i = start; i < end; i++)
		removeAt(str, start);
}

void RLE(char* str)
{
	const int minRepeatedLetters = 4;
	int len = strLen(str);
	int cnt = 0;
	int endIdx = 0;

	for (int i = 0; i < len; i++)
	{
		cnt = 1;
		while (i < len - 2 && str[i] == str[i + 1])
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
				int removeFrom = i - cnt + 5;
				int removeTo = i - cnt + 5 + removeUselessLetters;
				removeFromTo(str, removeFrom, removeTo);
			}
			i--;
		}
	}
}

int main()
{
	char str[] = "abcdddddaaaaaaabccdddzzzz";
	RLE(str);
	std::cout << str;

	return 0;
}