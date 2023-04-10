#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long lD;
	int iN, iM;
	cin >> lD >> iN >> iM;

	vector<long long> vecPos(iN + 2);
	for (int i = 1; i <= iN; ++i) cin >> vecPos[i];
	vecPos[0] = 0;
	vecPos[iN + 1] = lD;
	sort(vecPos.begin(), vecPos.end());


	long long lLeft = 0;
	long long lRight = lD;
	long long lAns = 0;

	while (lLeft <= lRight)
	{
		long long lMid = (lLeft + lRight) >> 1;
		int iCount = 0;
		int iIndex = 0;

		bool bPossible = true;

		for (int i = 1; i < iN + 1; ++i)
		{
			if (vecPos[i] - vecPos[iIndex] >= lMid)
			{
				++iCount;
				iIndex = i;
			}
		}
		if (iCount >= iN - iM)
		{
			lAns = max(lAns, lMid);
			lLeft = lMid + 1;
		}
		else
		{
			lRight = lMid - 1;
		}
	}
	cout << lAns << "\n";
	return 0;
}
