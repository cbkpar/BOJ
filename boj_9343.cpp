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
	vector<long long> vecFact(2000001, 0);
	vector<long long> vecInv(1000002, 0);
	vector<long long> vecFactInv(1000001, 0);
	vecFact[1] = vecInv[1] = vecFactInv[1] = 1;
	for (int i = 2; i <= 2000000; ++i)
	{
		vecFact[i] = (vecFact[i - 1] * i) % lMod;
	}
	for (int i = 1; i <= 1000001; ++i)
	{
		vecInv[i] = Pow(i, lMod - 2, lMod);
	}
	for (int i = 2; i <= 1000000; ++i)
	{
		vecFactInv[i] = (vecFactInv[i - 1] * vecInv[i]) % lMod;
	}


	int iT;
	cin >> iT;
	while (iT--)
	{
		int iN;
		cin >> iN;

		long long lAns = 1;
		lAns = (lAns * vecFact[iN * 2]) % lMod;
		lAns = (lAns * vecFactInv[iN]) % lMod;
		lAns = (lAns * vecFactInv[iN]) % lMod;
		lAns = (lAns * vecInv[iN + 1]) % lMod;
		cout << lAns << "\n";
	}
	return 0;
}
