#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iX, iY, iZ;
	cin >> iX >> iY >> iZ;

	int iU, iV, iW;
	cin >> iU >> iV >> iW;

	int iCost = 0;
	iCost += (iU / 100) * iX;
	iCost += (iV / 50) * iY;
	iCost += (iW / 20) * iZ;

	cout << iCost << "\n";
	return 0;
}
