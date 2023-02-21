#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iMinLen = 101;
	int iMaxLen = 0;

	int iCount = 0;
	int iRight = -1;

	for (int i = 0; i < 3; ++i)
	{
		int iS, iE;
		cin >> iS >> iE;
		iMinLen = min(iMinLen, iE - iS);
		iMaxLen = max(iMaxLen, iE - iS);

		if (iRight < iS)
		{
			++iCount;
		}
		iRight = max(iRight, iE);
	}

	cout << iCount << "\n";
	cout << iMinLen << " " << iMaxLen << "\n";
	return 0;
}
