#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iK;
	cin >> iN >> iK;

	int iMax = 0;
	int iNow = 0;
	for (int i = 0;i < iN;++i)
	{
		int iA, iB;
		cin >> iA >> iB;
		iNow += iA;
		iNow -= iB;
		iMax = max(iMax, iNow);
	}

	int iAns = max(0, iMax - iK);
	cout << iAns << "\n";
	return 0;
}
