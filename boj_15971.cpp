#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct tPos
{
	int iNow;
	int iTotal;
	int iMax;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iS, iE;
	cin >> iN >> iS >> iE;

	vector<vector<pair<int, int>>> vecNode(iN + 1, vector<pair<int, int>>());

	for (int i = 0; i < iN - 1; ++i)
	{
		int iStart, iEnd, iWeight;
		cin >> iStart >> iEnd >> iWeight;

		vecNode[iStart].push_back({ iEnd, iWeight });
		vecNode[iEnd].push_back({ iStart, iWeight });
	}

	vector<bool> vecVisited(iN + 1, false);

	queue<tPos> qPos;
	qPos.push({ iS,0,0 });
	vecVisited[iS] = true;

	int iAns = -1;
	while (!qPos.empty())
	{
		tPos tNowPos = qPos.front();
		qPos.pop();

		int iNow = tNowPos.iNow;
		int iTotal = tNowPos.iTotal;
		int iMax = tNowPos.iMax;

		if (iNow == iE)
		{
			cout << (iTotal - iMax) << "\n";
			break;
		}

		int iSize = vecNode[iNow].size();
		for (int i = 0; i < iSize; ++i)
		{
			if (!vecVisited[vecNode[iNow][i].first])
			{
				vecVisited[vecNode[iNow][i].first] = true;
				int iNext = vecNode[iNow][i].first;
				int iNextTotal = iTotal + vecNode[iNow][i].second;
				int iNextMax = max(iMax, vecNode[iNow][i].second);
				qPos.push({ iNext, iNextTotal, iNextMax });
			}
		}
	}
	return 0;
}
