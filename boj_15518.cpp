#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iH, iW;
	cin >> iN >> iH >> iW;

	int iAns = 0;
	for (int i = 0; i < iN; i += 2)
	{
		int iX1, iX2;
		cin >> iX1 >> iX2;

		int iS1, iE1, iS2, iE2;
		iS1 = iX1;
		iE1 = iW + iX1;
		iS2 = iW - iX2;
		iE2 = 2 * iW - iX2;
		int iDiff = max(iE1, iE2) - min(iS1, iS2);
		iAns += (2 * iW - iDiff) * iH;
	}
	cout << iAns << "\n";
	return 0;
}
