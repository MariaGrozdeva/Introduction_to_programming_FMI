#include <iostream>
using namespace std;

int main()
{
	int x, y;
	cin >> x >> y;

	bool isInside = false;
	int radius = 3;
	
	if (x <= 3 && x >= -3 && y >= 0 && y <= 4) 
	{
		if (x * x + y * y >= radius * radius)
			isInside = true;
	}

	if (isInside)
		cout << "Point is inside the figure.\n";	
	else 
		cout << "Point is not inside the figure.\n";
}