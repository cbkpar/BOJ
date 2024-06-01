#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int iIndex = 0;
vector<vector<int>> vecNode(100001, vector<int>());
vector<int> vecOrder(100001, 0);
vector<pair<int, int>> vecAns;

int FindBreaker(int iNum, int iPrev)
{
	int iOrder = ++iIndex;
	vecOrder[iNum] = iOrder;

	for (int iNext : vecNode[iNum])
	{
		if (iNext == iPrev) continue;
		if (vecOrder[iNext] > 0)
		{
			iOrder = min(iOrder, vecOrder[iNext]);
			continue;
		}

		int iNextOrder = FindBreaker(iNext, iNum);
		if (iNextOrder > vecOrder[iNum])
		{
			int iMin = min(iNum, iNext);
			int iMax = max(iNum, iNext);
			vecAns.push_back({ iMin, iMax });
		}
		iOrder = min(iOrder, iNextOrder);
	}

	return iOrder;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iV, iE;
	cin >> iV >> iE;
	while (iE--)
	{
		int iStart, iEnd;
		cin >> iStart >> iEnd;

		vecNode[iStart].push_back(iEnd);
		vecNode[iEnd].push_back(iStart);
	}

	for (int i = 1; i <= iV; ++i)
	{
		if (vecOrder[i] == 0)
		{
			FindBreaker(i, -1);
		}
	}

	sort(vecAns.begin(), vecAns.end());
	int iAns = vecAns.size();
	cout << iAns << "\n";
	for (pair<int, int> pAns : vecAns)
	{
		cout << pAns.first << " " << pAns.second << "\n";
	}
	return 0;
}
