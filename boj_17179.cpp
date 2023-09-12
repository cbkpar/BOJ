#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM, iL;
	cin >> iN >> iM >> iL;

	vector<int> vecLen(iM + 1, 0);
	for (int i = 1; i <= iM; ++i) cin >> vecLen[i];

	vector<int> vecDiff(iM + 1, 0);
	for (int i = 0; i < iM; ++i)
	{
		vecDiff[i] = vecLen[i + 1] - vecLen[i];
	}
	vecDiff[iM] = iL - vecLen[iM];

	while (iN--)
	{
		int iSlice;
		cin >> iSlice;
		int iAns = 0;

		int iCount = 0;
		int iLeft = 0;
		int iRight = iL;
		while (iLeft <= iRight)
		{
			int iMid = (iLeft + iRight) >> 1;
			int iSum = 0;
			int iTempCount = 0;
			for (int i = 0; i <= iM; ++i)
			{
				iSum += vecDiff[i];
				if (iSum >= iMid)
				{
					++iTempCount;
					iSum = 0;
				}
			}
			if (iTempCount > iSlice)
			{
				iAns = max(iAns, iMid);
				iLeft = iMid + 1;
			}
			else
			{
				iRight = iMid - 1;
			}
		}
		cout << iAns << "\n";
	}

	return 0;
}
