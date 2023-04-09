#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true)
	{
		int iN, iW, iL, iH, iP, iM;
		cin >> iN >> iW >> iL >> iH >> iP >> iM;
		if (iN == 0) break;

		int iNeed = (iW * iL) + (iW + iL) * iH * 2;
		while (iM--)
		{
			int iA, iB;
			cin >> iA >> iB;
			iNeed -= iA * iB;
		}
		iNeed *= iN;
		int iAns = (iNeed + iP - 1) / iP;
		cout << iAns << "\n";
	}
	return 0;
}
