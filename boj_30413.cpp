#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 1000000007

using namespace std;

long long CalcPow(long long lN, long long lCount, long long lMod)
{
	long long lRet = 1;
	long long lPower = lN;
	while (lCount > 0)
	{
		if (lCount & 1)
		{
			lRet = (lRet * lPower) % lMod;
		}
		lPower = (lPower * lPower) % lMod;
		lCount >>= 1;
	}
	return lRet;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long lA, lB;
	cin >> lA >> lB;

	if (lA == 1)
	{
		cout << (lB % MOD) << "\n";
		return 0;
	}

	long long lX = (CalcPow(lA % MOD, lB, MOD) + (MOD - 1)) % MOD;
	long long lY = CalcPow(lA - 1, MOD - 2, MOD);
	long long lAns = (lX * lY) % MOD;

	cout << lAns << "\n";
	return 0;
}
