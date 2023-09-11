#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;

	vector<int> vecCount(iN + 1, 0);
	vector<vector<int>> vecNode(iN + 1, vector<int>());

	while (iM--)
	{
		int iCount;
		cin >> iCount;
		vector<int> vecNum(iCount, 0);
		for (int i = 0; i < iCount; ++i) cin >> vecNum[i];
		for (int i = 0; i < iCount - 1; ++i)
		{
			vecNode[vecNum[i]].push_back(vecNum[i + 1]);
			++vecCount[vecNum[i + 1]];
		}
	}
	vector<int> vecAns;
	queue<int> qNum;
	for (int i = 1; i <= iN; ++i)
	{
		if (vecCount[i] == 0)
		{
			qNum.push(i);
		}
	}
	while (!qNum.empty())
	{
		int iNum = qNum.front();
		qNum.pop();
		vecAns.push_back(iNum);

		for (int iNext : vecNode[iNum])
		{
			if (--vecCount[iNext] == 0)
			{
				qNum.push(iNext);
			}
		}
	}

	if (vecAns.size() == iN)
	{
		for (int i = 0; i < iN; ++i)
		{
			cout << vecAns[i] << "\n";
		}
	}
	else
	{
		cout << "0" << "\n";
	}
	return 0;
}
