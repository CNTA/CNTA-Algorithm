#include <iostream>
#include <vector>
#include <algorithm>
#include <stdint.h>

using namespace std;

#define MIN_LONG (-(((int64_t)1) << 32))

int main()
{
	uint64_t arraySize, manipulations;
	cin >> arraySize >> manipulations;

	vector<int64_t> arr(arraySize, 0);
	for (int i = 0; i < manipulations; i++)
	{
		int startIndex, endIndex, valueToAdd;
		cin >> startIndex >> endIndex >> valueToAdd;

		arr[startIndex - 1] += valueToAdd;
		if (endIndex < arraySize)
			arr[endIndex] -= valueToAdd;
	}

	int64_t result = 0;
	int64_t max = MIN_LONG;
	for (int i = 0; i < arr.size(); i++)
	{
		result += arr[i];
		max = (max > result) ? max : result;
	}

	cout << max << endl;

	return 0;
}