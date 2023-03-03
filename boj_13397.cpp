#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;

	vector<int> vecNum(iN, 0);
	for (int i = 0; i < iN; ++i) cin >> vecNum[i];

	int iAns = 10000;

	int iLeft = 0;
	int iRight = 10000;
	while (iLeft <= iRight)
	{
		int iMid = (iLeft + iRight) >> 1;
		int iCount = 1;

		int iMin = 10000;
		int iMax = 0;
		for (int i = 0; i < iN; ++i)
		{
			iMin = min(iMin, vecNum[i]);
			iMax = max(iMax, vecNum[i]);
			if (iMax - iMin > iMid)
			{
				iMin = vecNum[i];
				iMax = vecNum[i];
				++iCount;
			}
		}
		if (iCount <= iM)
		{
			iAns = min(iAns, iMid);
			iRight = iMid - 1;
		}
		else
		{
			iLeft = iMid + 1;
		}
	}
	cout << iAns << "\n";

	return 0;
}
