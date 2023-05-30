#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long Sqrt(long long n) {
	if (n <= 1) return n;
	long long lo = 0, hi = n;
	while (lo <= hi) {
		long long mid = (lo + hi) / 2;
		if (mid > n / mid)
		{
			hi = mid - 1;
		}
		else {
			lo = mid + 1;
		}
	}
	return hi;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;

	int iK = Sqrt(iN);
	vector<int> vecCup(iN, 0);
	vector<int> vecBox(iN, 0);

	while (iM--)
	{
		int iCount, iStart;
		cin >> iCount >> iStart;

		int iAns = 0;

		int iS = (iStart - 1);
		int iE = (iStart + iCount - 1);

		while (iS < iE && iS % iK != 0)
		{
			++vecBox[iS];
			iAns += vecBox[iS];
			++iS;
		}
		if (iE != iN)
		{
			while (iS < iE && iE % iK != 0)
			{
				--iE;
				++vecBox[iE];
				iAns += vecBox[iE];
			}
		}
		while (iS < iE)
		{
			++vecCup[iS];
			iAns += vecCup[iS];
			iS += iK;
		}
		cout << iAns << "\n";
	}
	return 0;
}
