#include <iostream>
#include <vector>
#include <algorithm>

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

	long long lMod = 1000000007;

	long long lK, lN;
	cin >> lK >> lN;

	long long lAns = 1;
	for (long long i = lN; i <= lN + lK; ++i) lAns = (lAns * i) % lMod;
	for (long long i = 2; i <= lK + 1; ++i) lAns = (lAns * Pow(i, lMod - 2, lMod)) % lMod;

	cout << lAns << "\n";
	return 0;
}
