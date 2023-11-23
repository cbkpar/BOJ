#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int iN, iM, iK;
	cin >> iN >> iM >> iK;

	int iLeft = iN - iM * iK;
	int iRight = iN - iM * (iK - 1) - 1;

	if (iLeft < 0) iLeft = 0;
	if (iRight < 0) iRight = 0;

	cout << iLeft << " " << iRight << "\n";
	return 0;
}
