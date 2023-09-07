#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int dp[1001][1001][3] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;

	for (int i = 1; i <= iN; ++i)
	{
		for (int j = 0; j < iM; ++j)
		{
			dp[i][j][0] = 1000000000;
			dp[i][j][1] = 1000000000;
			dp[i][j][2] = 1000000000;
		}
	}
	for (int i = 1; i <= iN; ++i)
	{
		for (int j = 0; j < iM; ++j)
		{
			int iCost;
			cin >> iCost;

			if (j < iM - 1) dp[i][j][0] = min(dp[i - 1][j + 1][1], dp[i - 1][j + 1][2]) + iCost;
			dp[i][j][1] = min(dp[i - 1][j][0], dp[i - 1][j][2]) + iCost;
			if (j > 0) dp[i][j][2] = min(dp[i - 1][j - 1][0], dp[i - 1][j - 1][1]) + iCost;
		}
	}

	int iAns = 1000000000;
	for (int i = 0; i < iM; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			iAns = min(iAns, dp[iN][i][j]);
		}
	}
	cout << iAns << "\n";
	return 0;
}
