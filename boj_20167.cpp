#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long lAns = 0;

	int iN;
	long long lK;
	cin >> iN >> lK;

	vector<pair<int, long long>> vecDP;
	vecDP.push_back({ -1,0 });

	vector<long long> vecNum(iN);
	for (int i = 0; i < iN; ++i) cin >> vecNum[i];
	int iS = 0;
	int iE = 0;
	long long lSum = vecNum[0];
	while (true)
	{
		while (iE + 1 < iN && lSum < lK)
		{
			lSum += vecNum[++iE];
		}

		if (lSum > lK)
		{
			int iLeft = 0;
			int iRight = vecDP.size() - 1;
			while (iLeft <= iRight)
			{
				int iMid = (iLeft + iRight) / 2;
				if (vecDP[iMid].first < iS)
				{
					iLeft = iMid + 1;
				}
				else
				{
					iRight = iMid - 1;
				}
			}
			long long lTemp = vecDP[iLeft - 1].second + lSum - lK;
			vecDP.push_back({ iE, max(vecDP[vecDP.size() - 1].second,lTemp) });
			if (lAns < lTemp) lAns = lTemp;
		}

		while (iS + 1 < iN && lSum >= lK)
		{
			lSum -= vecNum[iS++];
		}
		if (iE + 1 == iN) break;
	}

	cout << lAns << "\n";
	return 0;
}
