#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iX, iY;
	cin >> iN >> iX >> iY;

	int iAnsCount = 0;
	int iAnsRest = 0;

	for (int i = 0;i < iN;++i)
	{
		int iNum;
		cin >> iNum;

		int iA = iNum / iX;
		int iB = iNum % iX - (iY - iX) * iA;
		if (iB < 0) iB = 0;
		iAnsCount += iA;
		iAnsRest += iB;
	}

	cout << iAnsCount << "\n";
	cout << iAnsRest << "\n";
	return 0;
}
