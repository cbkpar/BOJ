#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iR, iC;
	cin >> iR >> iC;

	vector<vector<int>> dp(iR);
	for (int i = 0; i < iR; ++i)
	{
		dp[i] = vector<int>(iC);
		for (int j = 0; j < iC; ++j)
		{
			cin >> dp[i][j];
			if (i > j) dp[i][j] = 0;
		}
	}
	for (int i = 1; i < iC; ++i)
	{
		for (int j = 0; j < iR; ++j)
		{
			int iMax = 0;
			if (j - 1 >= 0 && dp[j - 1][i - 1] > iMax) iMax = dp[j - 1][i - 1];
			if (dp[j][i - 1] > iMax) iMax = dp[j][i - 1];
			if (j + 1 < iR && dp[j + 1][i - 1] > iMax) iMax = dp[j + 1][i - 1];
			dp[j][i] += iMax;
		}
	}
	cout << dp[iR - 1][iC - 1] << "\n";
	return 0;
}
