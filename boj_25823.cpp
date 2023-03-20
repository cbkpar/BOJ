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
	vector<long long> vecFact(400001, 0);
	vector<long long> vecFactInv(200001, 0);
	vecFact[1] = vecFactInv[1] = 1;
	for (int i = 2; i <= 400000; ++i)
	{
		vecFact[i] = (vecFact[i - 1] * i) % lMod;
	}
	for (int i = 2; i <= 200000; ++i)
	{
		vecFactInv[i] = (vecFactInv[i - 1] * Pow(i, lMod - 2, lMod)) % lMod;
	}

	int iN;
	cin >> iN;

	long long lAns = 0;
	for (int i = 3; i <= iN; ++i)
	{
		lAns = (lAns + (vecFact[i * 2] * ((vecFactInv[i] * vecFactInv[i]) % lMod))) % lMod;
	}
	cout << lAns << "\n";
	return 0;
}
