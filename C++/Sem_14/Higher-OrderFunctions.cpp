#include <iostream>
#include <climits>

int applyOnArray(const int* arr, const size_t size, int initValue, int(*func)(int, int))
{
	if (size == 0)
	{
		return initValue;
	}

	return applyOnArray(arr + 1, size - 1, func(*arr, initValue), func);
}

int sumInArray(const int* arr, const size_t size)
{
	return applyOnArray(arr, size, 0, [](int x, int y) { return x + y; });
}

int productInArray(const int* arr, const size_t size)
{
	return applyOnArray(arr, size, 1, [](int x, int y) { return x * y; });
}

int maxElInArray(const int* arr, const size_t size)
{
	return applyOnArray(arr, size, INT_MIN, [](int x, int y) { return x > y ? x : y; });
}

int main()
{
	constexpr size_t SIZE = 4;
	int arr[SIZE] = { 1, 2, 3, 4 };

	std::cout << "Sum: " << sumInArray(arr, SIZE) << std::endl << "Product: " << productInArray(arr, SIZE) << std::endl << "Max: " << maxElInArray(arr, SIZE);
}
