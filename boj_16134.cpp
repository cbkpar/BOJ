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

	long long lMod = 1000000007;
	vector<long long> vecFact(1000001, 0);
	vector<long long> vecFactInv(1000001, 0);
	vecFact[0] = vecFactInv[0] = 1;
	vecFact[1] = vecFactInv[1] = 1;
	for (int i = 2; i <= 1000000; ++i)
	{
		vecFact[i] = (vecFact[i - 1] * i) % lMod;
		vecFactInv[i] = (vecFactInv[i - 1] * Pow(i, lMod - 2, lMod)) % lMod;
	}

	int iN, iK;
	cin >> iN >> iK;

	long long lAns = 1;
	lAns = (lAns * vecFact[iN]) % lMod;
	lAns = (lAns * vecFactInv[iN - iK]) % lMod;
	lAns = (lAns * vecFactInv[iK]) % lMod;

	cout << lAns << "\n";
	return 0;
}
