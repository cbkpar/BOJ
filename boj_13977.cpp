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

long long FactMod[4000001] = { 0, };
long long FactModInv[4000001] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	FactMod[0] = FactMod[1] = 1;
	for (int i = 2;i <= 4000000;++i)
	{
		FactMod[i] = (FactMod[i - 1] * i) % MOD;
	}

	FactModInv[0] = FactModInv[1] = 1;
	for (int i = 2;i <= 4000000;++i)
	{
		FactModInv[i] = (FactModInv[i - 1] * CalcPow(i, MOD - 2, MOD)) % MOD;
	}

	int iM;
	cin >> iM;
	while (iM-- > 0)
	{
		int iN, iK;
		cin >> iN >> iK;

		long long lAns = FactMod[iN];
		lAns = (lAns * FactModInv[iN - iK]) % MOD;
		lAns = (lAns * FactModInv[iK]) % MOD;
		cout << lAns << "\n";
	}

	return 0;
}
