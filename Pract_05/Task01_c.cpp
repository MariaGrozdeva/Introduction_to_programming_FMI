#include <iostream>
using namespace std;

int main()
{
	int x, y;
	cin >> x >> y;

	bool isInside = false;

	if (y >= -3 && y <= 2 && x >= -3 && x <= 3)
	{
		isInside = true;
	}
	else if (y >= 2)
	{
		int radius = 3;
		int distSquared = x * x + (y - 2) * (y - 2);
		if (distSquared <= radius * radius)
			isInside = true;
	}

	if (isInside)
	{
		cout << "Point is inside the figure!" << endl;
	}
	else
	{
		cout << "Point is outside the figure!" << endl;
	}
}
