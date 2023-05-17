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

	int iX, iY, iX1, iY1, iX2, iY2;
	cin >> iX >> iY >> iX1 >> iY1 >> iX2 >> iY2;

	int iDiffX = 0;
	int iDiffY = 0;

	if (iX < iX1) iDiffX = iX1 - iX;
	if (iX > iX2) iDiffX = iX - iX2;
	if (iY < iY1) iDiffY = iY1 - iY;
	if (iY > iY2) iDiffY = iY - iY2;

	cout << sqrt(iDiffX * iDiffX + iDiffY * iDiffY) << "\n";
	return 0;
}
