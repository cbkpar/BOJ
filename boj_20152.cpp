#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iH, iN;
	cin >> iH >> iN;
	iN = abs(iH - iN);

	vector<vector<long long>> dp(iN + 1, vector<long long>(iN + 1, 0));
	dp[0][0] = 1;
	for (int i = 0; i <= iN; ++i)
	{
		for (int j = 0; j <= iN; ++j)
		{
			if (i == 0 && j == 0) continue;
			if (i > j) continue;
			if (i > 0) dp[i][j] += dp[i - 1][j];
			if (j > 0) dp[i][j] += dp[i][j - 1];
		}
	}
	cout << dp[iN][iN] << "\n";
	return 0;
}
