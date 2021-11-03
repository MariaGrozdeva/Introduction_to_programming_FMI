#include <iostream>
using namespace std;

int main()
{
	int x, y;
	cin >> x >> y;

	bool isInside = false;

	if (y > 0)
	{
		int radius = 2;
		int distSquared = x * x + y * y;
		if (distSquared <= radius * radius)
			isInside = true;
	}
	else 
	{
		if (y >= -2) 
		{
			int radius = 2;
			int distSquared = (x - 4) * (x - 4) + y * y;
			if (distSquared <= radius * radius)
				isInside = true;
		}

		if (y >= -3)
		{
			int radius = 3;
			int distSquared = (x + 4) * (x + 4) + y * y;
			if (distSquared <= radius * radius)
				isInside = true;
		}
	}

	if (isInside)
		cout << "Point is inside the figure!" << endl;
	else
		cout << "Point is not inside the figure!" << endl;
}