#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int iIndex = 0;
vector<vector<int>> vecNode(10001, vector<int>());
vector<int> vecOrder(10001, 0);
vector<bool> vecBreaker(10001, false);

int FindBreaker(int iNum, bool bRoot)
{
	int iChild = 0;

	int iOrder = ++iIndex;
	vecOrder[iNum] = iOrder;

	for (int iNext : vecNode[iNum])
	{
		if (vecOrder[iNext] > 0)
		{
			iOrder = min(iOrder, vecOrder[iNext]);
			continue;
		}

		++iChild;
		int iNextOrder = FindBreaker(iNext, false);
		iOrder = min(iOrder, iNextOrder);
		if (!bRoot && iNextOrder >= vecOrder[iNum])
		{
			vecBreaker[iNum] = true;
		}
	}

	if (bRoot && iChild >= 2)
	{
		vecBreaker[iNum] = true;
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

	for (int i = 1;i <= iV;++i)
	{
		if (vecOrder[i] == 0)
		{
			FindBreaker(i, true);
		}
	}

	int iAns = 0;
	for (int i = 1;i <= iV;++i)
	{
		if (vecBreaker[i])
		{
			++iAns;
		}
	}
	cout << iAns << "\n";
	for (int i = 1;i <= iV;++i)
	{
		if (vecBreaker[i])
		{
			--iAns;
			cout << i << (iAns == 0 ? "\n" : " ");
		}
	}
	return 0;
}
