#include <iostream>
using namespace std;

int main() 
{
	cout << "Enter rows of pyramid: ";
	int rows;
	cin >> rows;

	int cols = 2 * rows - 1;
	int middle = cols / 2;

	for (size_t i = 0; i < rows; i++)
	{
		int fill = 1;

		for (size_t j = 0; j < cols; j++) 
		{
			if (j < middle - i || j > middle + i) 
			{
				cout << "  ";
				continue;
			}

			if (fill <= middle && j < middle) 
			{
				cout << fill << " ";
				++fill;
			} 
			else 
			{
				cout << fill << " ";
				--fill;
			}		
		}			
		cout << endl;
	}
}
