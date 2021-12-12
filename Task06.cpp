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

void RLE(const char* str)
{
	int len = strLen(str);
	int cnt = 0;

	for (int i = 0; i < len; i++)
	{
		cnt = 1;
		while (i < len - 1 && *(str + i) == *(str + i + 1))
		{
				i++;
				cnt++;
		}

		if (cnt >= 4)
			std::cout  << '(' << cnt << *(str + i) << ')';
		else
		{
			for (int j = 0; j < cnt; j++)
			{
				std::cout << *(str + i);
			}
		}
	}
}

int main()
{
	const char* str = "abcdddddaaaaaaabccdddzzzz";
	RLE(str);

	return 0;
}