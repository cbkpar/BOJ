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

	long long lMod = 987654321;
	vector<long long> dp(5001, 0);

	dp[0] = dp[1] = 1;
	for (int i = 2; i <= 5000; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			dp[i] = (dp[i] + dp[j] * dp[i - j - 1]) % lMod;
		}
	}

	int iN;
	cin >> iN;
	iN /= 2;
	cout << dp[iN] << "\n";

	return 0;
}
