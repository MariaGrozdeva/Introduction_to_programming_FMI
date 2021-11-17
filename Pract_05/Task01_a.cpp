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
	else if (y >= -3)
	{
		int radius = 3;
		
		int distSquaredRight = (x - 5) * (x - 5) + y * y;
		if (distSquaredRight <= radius * radius)
			isInside = true;
		
		int distSquaredLeft = (x + 5) * (x + 5) + y * y;
		if (distSquaredLeft <= radius * radius)
			isInside = true;	
	}

	if (isInside)
		cout << "Point is inside the figure!" << endl;
	else
		cout << "Point is not inside the figure!" << endl;
}
