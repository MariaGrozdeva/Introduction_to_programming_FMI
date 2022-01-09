#include <iostream>
using namespace std;

bool isPrefix(const char* str1, const char* prefix)
{
	int i = 0;
	while (prefix[i] != '\0')
	{
		if (str1[i] == '\0' || str1[i] != prefix[i])
			return false;
		i++;
	}
	return true;
}

void replaceSingleWordInBeggining(char* str1, int str2Len, char*& ptrToLastChangedSymbol)
{
	for (int i = 0; i < str2Len; i++)
	{
		str1[i] = '*';
		ptrToLastChangedSymbol = &str1[i];
	}
}
void replace(char* str1, const char* str2, char*& ptrToLastChangedSymbol)
{
	char* str1Iter = str1;
	int str2Len = strlen(str2);

	while (*str1Iter != '\0')
	{
		if (isPrefix(str1Iter, str2))
			replaceSingleWordInBeggining(str1Iter, str2Len, ptrToLastChangedSymbol);
		else
			str1Iter++;
	}
}

int main()
{
	const int maxSize= 1024;

	char str1[maxSize];
	char str2[maxSize];
	char* ptrToLastChangedSymbol = nullptr;

	cin.getline(str1, maxSize);
	cin.getline(str2, maxSize);

	replace(str1, str2, ptrToLastChangedSymbol);

	cout << str1 << endl;
	if (ptrToLastChangedSymbol)
		cout << ptrToLastChangedSymbol;
	else
		cout << "NULL";
}