
#include <iostream>
using namespace std;
bool isPalindrome(char* array,int start, int end)
{
	if (end - start == 1 || start == end)
		return true;
	else
	{
		if (array[start] == array[end])
			return isPalindrome(array, start + 1, end - 1);
		else
			return false;
	}
}
int main()
{
	char palindrome[256];
	cin.getline(palindrome, 256);

	int size = strlen(palindrome);


	if (isPalindrome(palindrome, 0, size - 1))
		cout << "True" << endl;
	else
		cout << "False" << endl;
	
	
}
