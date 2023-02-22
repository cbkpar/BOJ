#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iL, iR, iX;
	cin >> iN >> iL >> iR >> iX;

	vector<int> vecLevel(iN);
	for (int i = 0; i < iN; ++i) cin >> vecLevel[i];

	int iAns = 0;

	int iMax = 1 << iN;
	for (int i = 1; i < iMax; ++i)
	{
		int iTemp = i;
		int iMaxLevel = 0;
		int iMinLevel = 1000000000;
		int iSum = 0;
		for (int j = 0; j < iN; ++j)
		{
			if (iTemp & 1)
			{
				iSum += vecLevel[j];
				iMaxLevel = max(iMaxLevel, vecLevel[j]);
				iMinLevel = min(iMinLevel, vecLevel[j]);
			}
			iTemp /= 2;
		}
		if ((iMaxLevel - iMinLevel) >= iX && iL <= iSum && iSum <= iR) ++iAns;
	}

	cout << iAns << "\n";
	return 0;
}
