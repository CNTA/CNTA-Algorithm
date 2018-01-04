#include <iostream>
#include <vector>

using namespace std;

void performSequence1(int x, int y, vector<vector<int>>& seqList, int lastAnswer)
{
	int seqIndex = ((x ^ lastAnswer) % seqList.size());
	if (seqIndex < 0 || seqIndex >= seqList.size())
		return;

	seqList.at(seqIndex).push_back(y);
}

void performSequence2(int x, int y, vector<vector<int>>& seqList, int& lastAnswer)
{
	int seqIndex = ((x ^ lastAnswer) % seqList.size());
	if (seqIndex < 0 || seqIndex >= seqList.size())
		return;

	const vector<int>& seq = seqList.at(seqIndex);
	int elementIndex = y % seq.size();

	if (elementIndex < 0 || elementIndex >= seq.size())
		return;

	lastAnswer = seq[elementIndex];
	cout << lastAnswer << endl;
}

int main()
{
	int numSequences, numQueries;
	cin >> numSequences >> numQueries;

	vector<vector<int>> seqList;
	for (int i = 0; i < numSequences; i++)
	{
		seqList.push_back(vector<int>());
	}

	int lastAnswer = 0;

	for (int i = 0; i < numQueries; i++)
	{
		int queryType, x, y;
		cin >> queryType >> x >> y;

		switch (queryType)
		{
		case 1:
			performSequence1(x, y, seqList, lastAnswer);
			break;
		case 2:
			performSequence2(x, y, seqList, lastAnswer);
			break;
		default:
			break;
		}
	}

	return 0;
}