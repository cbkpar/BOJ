#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	string strDir;
	cin >> strDir;

	vector<int> vecNum(iN);
	for (int i = 0; i < iN; ++i) cin >> vecNum[i];

	vector<int> dpLeft(iN, 0);
	vector<int> dpRight(iN, 0);

	vector<int> vecTemp(iN + 1, 0);
	vecTemp[0] = -1;

	int iIndex = 1;
	for (int i = 0; i < iN; ++i)
	{
		if (strDir[i] == 'L')
		{
			if (vecNum[i] > vecTemp[iIndex - 1])
			{
				vecTemp[iIndex++] = vecNum[i];
			}
			else
			{
				int iLeft = 0;
				int iRight = iIndex - 1;
				while (iLeft < iRight)
				{
					int iMid = (iLeft + iRight) >> 1;
					if (vecTemp[iMid] < vecNum[i])
					{
						iLeft = iMid + 1;
					}
					else
					{
						iRight = iMid;
					}
				}
				vecTemp[iLeft] = vecNum[i];
			}
		}
		dpLeft[i] = iIndex - 1;
	}

	iIndex = 1;
	for (int i = iN - 1; i >= 0; --i)
	{
		if (strDir[i] == 'R')
		{
			if (vecNum[i] > vecTemp[iIndex - 1])
			{
				vecTemp[iIndex++] = vecNum[i];
			}
			else
			{
				int iLeft = 0;
				int iRight = iIndex - 1;
				while (iLeft < iRight)
				{
					int iMid = (iLeft + iRight) >> 1;
					if (vecTemp[iMid] < vecNum[i])
					{
						iLeft = iMid + 1;
					}
					else
					{
						iRight = iMid;
					}
				}
				vecTemp[iLeft] = vecNum[i];
			}
		}
		dpRight[i] = iIndex - 1;
	}
	int iMax = 1;
	for (int i = 0; i < iN; ++i)
	{
		iMax = max(iMax, dpLeft[i] + dpRight[i]);
	}
	cout << (iN - iMax) << "\n";
	return 0;
}
