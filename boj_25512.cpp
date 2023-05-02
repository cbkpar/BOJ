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

	int iN;
	cin >> iN;

	vector<vector<int>> vecNode(iN, vector<int>());
	for (int i = 1; i < iN; ++i)
	{
		int iS, iE;
		cin >> iS >> iE;
		vecNode[iS].push_back(iE);
		vecNode[iE].push_back(iS);
	}
	vector<pair<long long, long long>> vecCost(iN);
	for (int i = 0; i < iN; ++i)
	{
		cin >> vecCost[i].first >> vecCost[i].second;
	}

	vector<long long> vecSum(2, 0);
	vector<bool> vecVisited(iN, false);

	queue<int> qNode;
	qNode.push(0);
	vecVisited[0] = true;
	int iType = 0;
	while (!qNode.empty())
	{
		int iSize = qNode.size();
		while (iSize--)
		{
			int iPos = qNode.front();
			qNode.pop();
			vecSum[iType] += vecCost[iPos].first;
			vecSum[(iType + 1) % 2] += vecCost[iPos].second;

			for (int iNext : vecNode[iPos])
			{
				if (!vecVisited[iNext])
				{
					vecVisited[iNext] = true;
					qNode.push(iNext);
				}
			}
		}
		iType = (iType + 1) % 2;
	}
	cout << min(vecSum[0], vecSum[1]) << "\n";
	return 0;
}
