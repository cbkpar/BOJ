#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long Convert(long long lN, long long lD)
{
	long long lTemp = lN;
	long long lRes = 0;
	long long lPow = 1;
	while (lTemp > 0)
	{
		lRes += (lTemp % 10) * lPow;
		lTemp /= 10;
		lPow *= lD;
	}
	return lRes;
}

long long CalcMax(long long lN)
{
	long long lRes = 0;
	while (lN > 0)
	{
		lRes = max(lRes, lN % 10);
		lN /= 10;
	}
	return lRes;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	while (iT-- > 0)
	{
		long long lP, lQ, lR;
		cin >> lP >> lQ >> lR;

		long long lMax = 0;
		lMax = max(lMax, CalcMax(lP));
		lMax = max(lMax, CalcMax(lQ));
		lMax = max(lMax, CalcMax(lR));

		long long lAns = 0;

		for (int i = 16; i > lMax; --i)
		{
			long long lRes = Convert(lR, i);
			if (lRes == Convert(lP, i) * Convert(lQ, i))
			{
				lAns = i;
			}
		}

		cout << lAns << "\n";
	}

	return 0;
}
