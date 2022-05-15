#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
	vector<pair<int, int>> vecStduent;
	int iN, iM;
	cin >> iN >> iM;
	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iM; ++j)
		{
			int iAbility;
			cin >> iAbility;
			vecStduent.push_back({ i, iAbility });
		}
	}
	sort(vecStduent.begin(), vecStduent.end(),
		[](const pair<int, int>& o1, const pair<int, int>& o2)->bool {
			return o1.second < o2.second;
		});
	int iLeft = 0;
	int iRight = 0;
	int iCount = 0;
	int iMinDiff = 2100000000;
	int* pCheck = new int[iN];
	memset(pCheck, 0, sizeof(int) * iN);
	while (iRight < iN * iM)
	{
		while (iCount < iN)
		{
			if (0 == pCheck[vecStduent[iRight].first])
			{
				++iCount;
			}
			++pCheck[vecStduent[iRight].first];
			if (iCount == iN)
			{
				int iDiff = vecStduent[iRight].second - vecStduent[iLeft].second;
				if (iDiff < iMinDiff)
				{
					iMinDiff = iDiff;
				}
			}
			if (iN * iM == ++iRight)
			{
				break;
			}
		}
		while (iCount >= iN)
		{
			if (0 == --pCheck[vecStduent[iLeft].first])
			{
				--iCount;
			}
			++iLeft;
			if (iCount == iN)
			{
				int iDiff = vecStduent[iRight-1].second - vecStduent[iLeft].second;
				if (iDiff < iMinDiff)
				{
					iMinDiff = iDiff;
				}
			}
		}
	}
	cout << iMinDiff << endl;
	delete[] pCheck;
	return 0;
}
