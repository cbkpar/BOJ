#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iK;
	cin >> iN >> iK;

	vector<int> vecNum(iN);
	vector<int> vecSort(iN);
	for (int i = 0; i < iN; ++i)
	{
		cin >> vecNum[i];
		vecSort[i] = vecNum[i];
	}
	sort(vecSort.begin(), vecSort.end());

	int iLeft = 0;
	int iRight = iN - 1;
	int iAns = iN - 1;
	while (iLeft <= iRight)
	{
		int iMid = (iLeft + iRight) >> 1;
		bool bPossible = true;
		int iCount = 0;
		int iNum = vecSort[iMid];
		for (int i = 0; i < iN; ++i)
		{
			if (vecNum[i] > iNum)
			{
				++iCount;
			}
			else
			{
				iCount = 0;
			}
			if (iCount >= iK)
			{
				bPossible = false;
				break;
			}
		}
		if (bPossible)
		{
			iRight = iMid - 1;
			iAns = min(iAns, iMid);
		}
		else
		{
			iLeft = iMid + 1;
		}
	}
	cout << vecSort[iAns] << "\n";
	return 0;
}
