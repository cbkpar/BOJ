#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[101][101][2] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	dp[0][0][0] = 1;

	for (int i = 1; i <= 100; ++i)
	{
		for (int j = 0; j <= 100; ++j)
		{
			dp[i][j][0] += dp[i - 1][j][0];
			dp[i][j][0] += dp[i - 1][j][1];

			if (j >= 1) dp[i][j][1] += dp[i - 1][j - 1][1];
			dp[i][j][1] += dp[i - 1][j][0];
		}
	}

	int iT;
	cin >> iT;
	while (iT--)
	{
		int iN, iK;
		cin >> iN >> iK;
		cout << (dp[iN][iK][0] + dp[iN][iK][1]) << "\n";
	}
	return 0;
}
