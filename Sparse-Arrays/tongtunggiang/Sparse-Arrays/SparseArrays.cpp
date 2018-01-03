#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
	int numberOfStrings, queries;
	cin >> numberOfStrings;

	map<string, int> inputStrings;
	for (int i = 0; i < numberOfStrings; i++)
	{
		string input;
		cin >> input;

		if (inputStrings.count(input) <= 0)
		{
			inputStrings[input] == 0;
		}

		inputStrings[input]++;
	}

	cin >> queries;
	vector<int> queriesOccurence(queries);
	for (int i = 0; i < queries; i++)
	{
		string query;
		cin >> query;

		if (inputStrings.count(query) > 0)
		{
			queriesOccurence[i] = inputStrings[query];
		}
		else
		{
			queriesOccurence[i] = 0;
		}
	}

	cin.ignore();

	for (int i = 0; i < queries; i++)
		cout << queriesOccurence[i] << endl;

	return 0;
}