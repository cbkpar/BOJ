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

	vector<vector<int>> vecNode(iN + 1);
	vector<int> vecScore(iN + 1, 0);
	for (int i = 1; i <= iN; ++i)
	{
		int iSuper;
		cin >> iSuper;
		if (i == 1) continue;
		vecNode[iSuper].push_back(i);
	}
	while (iM--)
	{
		int iS, iScore;
		cin >> iS >> iScore;
		vecScore[iS] += iScore;
	}
	queue<int> qNum;
	qNum.push(1);
	while (!qNum.empty())
	{
		int iNum = qNum.front();
		qNum.pop();
		for (int iNext : vecNode[iNum])
		{
			vecScore[iNext] += vecScore[iNum];
			qNum.push(iNext);
		}
	}

	for (int i = 1; i <= iN; ++i)
	{
		cout << vecScore[i] << (i == iN ? "\n" : " ");
	}
	return 0;
}
