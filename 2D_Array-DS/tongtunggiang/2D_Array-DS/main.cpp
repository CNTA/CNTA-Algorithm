#include <iostream>
#include <vector>

using namespace std;

#define INDEX(row, col) ((row) * 6 + col)

int getHourglassSum(int* arr, int topIndex, int leftIndex)
{
	return arr[INDEX(topIndex, leftIndex)] + arr[INDEX(topIndex, leftIndex + 1)] + arr[INDEX(topIndex, leftIndex + 2)] +
		arr[INDEX(topIndex + 1, leftIndex + 1)] +
		arr[INDEX(topIndex + 2, leftIndex)] + arr[INDEX(topIndex + 2, leftIndex + 1)] + arr[INDEX(topIndex + 2, leftIndex + 2)];
}

int main()
{
	int arr[6 * 6];
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cin >> arr[INDEX(i, j)];
		}
	}

	int maxHourglassSum = getHourglassSum(arr, 0, 0);
	for (int i = 0; i <= 3; i++)
	{
		for (int j = 0; j <= 3; j++)
		{
			int hourglassSum = getHourglassSum(arr, i, j);
			if (hourglassSum > maxHourglassSum)
				maxHourglassSum = hourglassSum;
		}
	}

	cout << maxHourglassSum << endl;

	return 0;
}
