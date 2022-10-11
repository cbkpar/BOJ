#include <iostream>
#include <string>
#include <memory.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string strGold;
	cin >> strGold;
	int iGold = 0;
	iGold += (strGold[0] - '0') * 100;
	iGold += (strGold[2] - '0') * 10;
	iGold += (strGold[3] - '0') * 1;
	int iFreeze = iGold / 99;
	if (iFreeze > 2)
	{
		iFreeze = 2;
	}
	int iDay;
	cin >> iDay;
	int iLeft = 1;
	int iRight = 1;
	int iCount = 0;
	int iMax = 0;
	int iCountMax = 0;
	int* arrNumber = new int[iDay + 1];
	memset(arrNumber, 0, sizeof(int) * (iDay + 1));
	for (int i = 1; i <= iDay; ++i)
	{
		cin >> arrNumber[i];
		if (arrNumber[i] > iMax)
		{
			iMax = arrNumber[i];
		}
	}
	for (int i = 1; i <= iDay; ++i)
	{
		if (arrNumber[iRight] == 0)
		{
			++iCount;
			if (iCount < iFreeze)
			{
				++iRight;
			}
			else
			{
				while (iCount > iFreeze)
				{
					if (arrNumber[iLeft] == 0)
					{
						--iCount;
					}
					++iLeft;
				}
				++iRight;
			}
		}
		else
		{
			++iRight;
		}
		if (iRight - iLeft> iCountMax)
		{
			iCountMax = iRight - iLeft;
		}
	}
	cout << iCountMax << "\n";
	cout << iMax << "\n";
	return 0;
}
