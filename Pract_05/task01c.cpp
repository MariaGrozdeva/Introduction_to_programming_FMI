
#include <iostream>
using namespace std;
int main()
{
	int x, y;
	cin >> x >> y;

	bool is_inside = false;
	int radius = 3;

	int distance = x * x + (y - 1) * (y - 1);
	if ((x >= -3 && x <= 3) && (y >= -3 && y <= 1))
		is_inside = true;

	if (y > 1)
	{
		if (distance <= radius * radius)
			is_inside = true;
	}

	if (is_inside)
		cout << "Is inside the figure!";
	else
		cout << "Is not inside the figure!";
}

