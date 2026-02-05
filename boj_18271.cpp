#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iR;
	cin >> iR;
	
	int iDraw = 1;
	int iA = 0;
	int iB = 0;
	int iMax = 0;
	int iNow = 0;
	int iStreak = 0;

	for (int i = 0; i < iR; ++i)
	{
		int iWin;
		cin >> iWin;
		if (iWin == 1)
		{
			++iA;
			if (iStreak == 1)
			{
				++iNow;
				if (iA - iNow < iB && iA > iB)
				{
					iMax = max(iMax, iNow);
				}
			}
			else
			{
				iStreak = 1;
				iNow = 1;
			}
		}
		else
		{
			++iB;
			if (iStreak == 2)
			{
				++iNow;
				if (iB - iNow < iA && iB > iA)
				{
					iMax = max(iMax, iNow);
				}
			}
			else
			{
				iStreak = 2;
				iNow = 1;
			}
		}
		if (iA == iB)
		{
			++iDraw;
		}
	}

	cout << iA << " " << iB << "\n";
	cout << iDraw << "\n";
	cout << iMax << "\n";

	return 0;
}
