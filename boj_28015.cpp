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

	int iAns = 0;

	for (int i = 0; i < iN; ++i)
	{
		int iRed = 0;
		int iBlue = 0;
		int iBefore = 0;
		for (int i = 0; i < iM; ++i)
		{
			int iColor;
			cin >> iColor;

			if (iColor == 0)
			{
				if (iRed == 0 && iBlue == 0) continue;
				iAns += min(iRed, iBlue) + 1;
				iRed = iBlue = 0;
				iBefore = 0;
			}
			else if (iColor == 1)
			{
				if (iBefore != 1) ++iRed;
				iBefore = 1;
			}
			else if (iColor == 2)
			{
				if (iBefore != 2) ++iBlue;
				iBefore = 2;
			}
		}
		if (iRed != 0 || iBlue != 0) iAns += min(iRed, iBlue) + 1;
	}
	cout << iAns << "\n";
	return 0;
}
