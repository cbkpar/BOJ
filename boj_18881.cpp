#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	vector<pair<int, int>> vecPos(iN, { 0,0 });
	for (int i = 0; i < iN; ++i)
	{
		cin >> vecPos[i].first >> vecPos[i].second;
	}

	sort(vecPos.begin(), vecPos.end());

	int iR = 100000000;
	for (int i = 1; i < iN; ++i)
	{
		if (vecPos[i].second != vecPos[i - 1].second)
		{
			iR = min(iR, vecPos[i].first - vecPos[i - 1].first);
		}
	}

	int iAns = 0;
	int iNow = -1000000000;

	for (int i = 0; i < iN; ++i)
	{
		if (vecPos[i].second == 1)
		{
			if (iNow + iR <= vecPos[i].first)
			{
				++iAns;
			}
			iNow = vecPos[i].first;
		}
	}

	cout << iAns << "\n";
	return 0;
}
