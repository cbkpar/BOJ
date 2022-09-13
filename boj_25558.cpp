#include <iostream>

using namespace std;

int main()
{
	int iN;
	cin >> iN;
	int iSX, iSY, iEX, iEY;
	cin >> iSX >> iSY >> iEX >> iEY;
	int iAns = -1;
	long lMaxDist = 2000000000000000L;
	for (int i = 1; i <= iN; ++i)
	{
		int iRoute;
		cin >> iRoute;
		int iBeforeX = iSX;
		int iBeforeY = iSY;
		long lSumDist = 0;
		while (iRoute--)
		{
			int iNextX, iNextY;
			cin >> iNextX >> iNextY;
			lSumDist += abs(iNextX - iBeforeX);
			lSumDist += abs(iNextY - iBeforeY);
			iBeforeX = iNextX;
			iBeforeY = iNextY;
		}
		lSumDist += abs(iEX - iBeforeX);
		lSumDist += abs(iEY - iBeforeY);
		if (lSumDist < lMaxDist)
		{
			lMaxDist = lSumDist;
			iAns = i;
		}
	}
	cout << iAns << endl;
	return 0;
}
