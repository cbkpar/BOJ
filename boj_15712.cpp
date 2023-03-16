#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long dp[100001] = { 0, };

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

long long multiply(long long lR, long long lN, long long lMod)
{
	if (lN <= 100000)
	{
		if (dp[lN] != -1) return dp[lN];
		if (lN % 2 == 0)
		{
			return dp[lN] = (multiply(lR, lN / 2 - 1, lMod) * (1 + Pow(lR, lN / 2, lMod)) + Pow(lR, lN, lMod)) % lMod;
		}
		else
		{
			return dp[lN] = (multiply(lR, lN / 2, lMod) * (1 + Pow(lR, lN / 2 + 1, lMod))) % lMod;
		}
	}
	else
	{
		if (lN % 2 == 0)
		{
			return (multiply(lR, lN / 2 - 1, lMod) * (1 + Pow(lR, lN / 2, lMod)) + Pow(lR, lN, lMod)) % lMod;
		}
		else
		{
			return (multiply(lR, lN / 2, lMod) * (1 + Pow(lR, lN / 2 + 1, lMod))) % lMod;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i <= 100000; ++i) dp[i] = -1;

	long long lA, lR, lN, lMod;
	cin >> lA >> lR >> lN >> lMod;

	dp[0] = 1;
	dp[1] = (1 + lR) % lMod;

	long long lAns = (lA * multiply(lR, lN - 1, lMod)) % lMod;
	cout << lAns << "\n";
	return 0;
}
