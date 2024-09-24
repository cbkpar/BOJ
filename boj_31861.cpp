#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;

	vector<vector<long long>> dp(iM + 1, vector<long long>(26, 0));
	for (int i = 0;i < 26;++i)
	{
		dp[1][i] = 1;
	}

	for (int i = 2;i <= iM;++i)
	{
		for (int j = 0;j < 26;++j)
		{
			for (int k = 0;k < 26;++k)
			{
				if (abs(j - k) >= iN)
				{
					dp[i][j] = (dp[i][j] + dp[i - 1][k])%1000000007;
				}
			}
		}
	}

	long long lAns = 0;
	for (int i = 0;i < 26;++i)
	{
		lAns = (lAns + dp[iM][i]) % 1000000007;
	}
	cout << lAns << "\n";
	return 0;
}
