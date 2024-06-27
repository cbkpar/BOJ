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

	vector<long long> vecDist(iN + 1, 0);
	vector<bool> vecVisited(iN + 1, false);

	vector<vector<pair<int, long long>>> vecNode(iN + 1, vector<pair<int, long long>>());
	for (int i = 0;i < iN - 1;++i)
	{
		int iS, iE;
		long long lDist;
		cin >> iS >> iE >> lDist;
		vecNode[iS].push_back({ iE, lDist });
		vecNode[iE].push_back({ iS, lDist });
	}

	long long lAns = 0;
	queue<int> qPos;
	qPos.push(1);
	vecVisited[1] = true;

	while (!qPos.empty())
	{
		int iNowPos = qPos.front();
		qPos.pop();

		for (const pair<int, long long>& pNext : vecNode[iNowPos])
		{
			if (vecVisited[pNext.first])
			{
				continue;
			}
			vecVisited[pNext.first] = true;
			vecDist[pNext.first] = vecDist[iNowPos] + pNext.second;
			lAns = max(lAns, vecDist[pNext.first]);
			qPos.push(pNext.first);
		}
	}

	cout << lAns << "\n";
	return 0;
}
