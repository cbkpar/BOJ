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
	vector<int> vecRevCount(iN + 1, 0);
	vector<vector<pair<int, int>>> vecNode(iN + 1, vector<pair<int, int>>());
	vector<vector<pair<int, int>>> vecRevNode(iN + 1, vector<pair<int, int>>());
	for (int i = 0;i < iM;++i)
	{
		int iS, iE, iW;
		cin >> iS >> iE >> iW;
		vecNode[iS].push_back({ iE,iW });
		vecRevNode[iE].push_back({ iS,iW });
		++vecCount[iE];
		++vecRevCount[iS];
	}
	
	vector<bool> vecMax(iN + 1, false);
	vector<int> vecDist(iN + 1, 0);
	int iStart, iEnd;
	cin >> iStart >> iEnd;

	queue<int> qPos;
	qPos.push(iStart);
	while (!qPos.empty())
	{
		int iPos = qPos.front();
		qPos.pop();

		for (const pair<int, int>& pPos : vecNode[iPos])
		{
			int iNext = pPos.first;
			int iWeight = pPos.second;

			if (vecDist[iNext] < vecDist[iPos] + iWeight)
			{
				vecDist[iNext] = vecDist[iPos] + iWeight;
			}
			
			if (--vecCount[iNext] == 0)
			{
				qPos.push(iNext);
			}
		}
	}

	int iAnsRoute = 0;
	vecMax[iEnd] = true;
	qPos.push(iEnd);
	while (!qPos.empty())
	{
		int iPos = qPos.front();
		qPos.pop();

		for (const pair<int, int>& pPos : vecRevNode[iPos])
		{
			int iNext = pPos.first;
			int iWeight = pPos.second;

			if (vecDist[iNext] + iWeight == vecDist[iPos])
			{
				if (vecMax[iPos])
				{
					++iAnsRoute;
					vecMax[iNext] = true;
				}
			}

			if (--vecRevCount[iNext] == 0)
			{
				qPos.push(iNext);
			}
		}

	}

	cout << vecDist[iEnd] << "\n";
	cout << iAnsRoute << "\n";
	return 0;
}
