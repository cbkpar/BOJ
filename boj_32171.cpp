#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	int iXMin = 100000;
	int iXMax = -100000;
	int iYMin = 100000;
	int iYMax = -100000;

	for (int i = 0; i < iN; ++i)
	{
		int iX1, iY1, iX2, iY2;
		cin >> iX1 >> iY1 >> iX2 >> iY2;
		iXMin = min(iXMin, iX1);
		iXMax = max(iXMax, iX2);
		iYMin = min(iYMin, iY1);
		iYMax = max(iYMax, iY2);

		int iMeter = (iXMax - iXMin) * 2 + (iYMax - iYMin) * 2;
		cout << iMeter << "\n";
	}
	return 0;
}
