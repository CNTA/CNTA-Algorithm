#include <iostream>
#include <vector>

using namespace std;

vector <int> leftRotation(vector <int> a, int d) 
{
	if (d < 0 || d >= a.size())
	{
		return vector<int>();
	}

	vector<int> result;
	for (int i = d; i < a.size(); i++)
	{
		result.push_back(a[i]);
	}
	for (int i = 0; i < d; i++)
	{
		result.push_back(a[i]);
	}

	return result;
}

int main() 
{
	int arraySize;
	int shiftAmount;
	cin >> arraySize >> shiftAmount;
	vector<int> arr(arraySize);
	for (int i = 0; i < arraySize; i++)
	{
		cin >> arr[i];
	}

	vector <int> result = leftRotation(arr, shiftAmount);
	for (size_t i = 0; i < result.size(); i++) 
	{
		cout << result[i] << (i != result.size() - 1 ? " " : "");
	}
	cout << endl;


	return 0;
}
