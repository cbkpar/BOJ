#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	int iMinX = 1000000;
	int iMaxX = 0;
	int iMinY = 1000000;
	int iMaxY = 0;

	while (iN--)
	{
		int iX, iY;
		cin >> iX >> iY;
		iMinX = min(iMinX, iX);
		iMaxX = max(iMaxX, iX);
		iMinY = min(iMinY, iY);
		iMaxY = max(iMaxY, iY);
	}
	int iDiffX = iMaxX - iMinX;
	int iDiffY = iMaxY - iMinY;

	cout << max(iDiffX, iDiffY) * max(iDiffX, iDiffY) << "\n";
	return 0;
}
