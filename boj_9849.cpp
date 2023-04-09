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

	int iMinX = 10000;
	int iMaxX = 0;
	int iMinY = 10000;
	int iMaxY = 0;

	for (int i = 0; i < iN; ++i)
	{
		int iX1, iX2, iY1, iY2;
		cin >> iX1 >> iX2 >> iY1 >> iY2;
		iMinX = min(iMinX, iX2);
		iMaxX = max(iMaxX, iX1);
		iMinY = min(iMinY, iY2);
		iMaxY = max(iMaxY, iY1);
	}
	if (iMaxX >= iMinX || iMaxY >= iMinY)
	{
		cout << "0\n";
	}
	else
	{
		cout << (iMaxX - iMinX) * (iMaxY - iMinY) << "\n";
	}
	return 0;
}
