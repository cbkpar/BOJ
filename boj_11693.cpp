#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

long long Pow(long long lNum, long long lPow, long long lMod)
{
	long long lAns = 1;
	long long lTemp = lNum;
	while (lPow)
	{
		if (lPow & 1)
		{
			lAns = (lAns * lTemp) % lMod;
		}
		lTemp = (lTemp * lTemp) % lMod;
		lPow /= 2;
	}
	return lAns;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long lN, lM;
	cin >> lN >> lM;

	long long lMod = 1000000007;

	long long lAns = 1;
	long long lSqrt = (long long)sqrt(lN);
	for (long long i = 2; i <= lSqrt; ++i)
	{
		long long lCount = 0;
		while (true)
		{
			if (lN % i != 0) break;
			lN /= i;
			++lCount;
		}
		if (lCount)
		{
			lAns = (lAns * (Pow(i, lCount * lM + 1, lMod) + lMod - 1)) % lMod;
			lAns = (lAns * (Pow(i - 1, lMod - 2, lMod))) % lMod;
		}
	}
	if (lN > 1)
	{
		lAns = (lAns * (Pow(lN, lM + 1, lMod) + lMod - 1)) % lMod;
		lAns = (lAns * (Pow(lN - 1, lMod - 2, lMod))) % lMod;
	}
	cout << lAns << "\n";
	return 0;
}
