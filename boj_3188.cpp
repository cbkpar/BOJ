#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	vector<vector<int>> matMap(iN);
	for (int i = 0; i < iN; ++i)
	{
		matMap[i].resize(iN);
		for (int j = 0; j < iN; ++j)
		{
			cin >> matMap[i][j];
		}
	}
	vector<vector<pair<int, int>>> dp(iN);
	for (int i = 0; i < iN; ++i) dp[i].resize(iN, { 0,0 });

	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iN; ++j)
		{
			if (i == 0 && j == 0)
			{
				int iNum = matMap[0][0];
				dp[0][0].first = dp[0][0].second = 0;
				while (iNum && iNum % 2 == 0)
				{
					iNum /= 2;
					++dp[0][0].first;
				}
				while (iNum && iNum % 5 == 0)
				{
					iNum /= 5;
					++dp[0][0].second;
				}
				continue;
			}
			dp[i][j].first = 100000000;
			dp[i][j].second = 100000000;
			if (matMap[i][j] == 0) continue;
			if (i > 0)
			{
				dp[i][j].first = min(dp[i][j].first, dp[i - 1][j].first);
				dp[i][j].second = min(dp[i][j].second, dp[i - 1][j].second);
			}
			if (j > 0)
			{
				dp[i][j].first = min(dp[i][j].first, dp[i][j - 1].first);
				dp[i][j].second = min(dp[i][j].second, dp[i][j - 1].second);
			}
			int iNum = matMap[i][j];
			while (iNum && iNum % 2 == 0)
			{
				iNum /= 2;
				++dp[i][j].first;
			}
			while (iNum && iNum % 5 == 0)
			{
				iNum /= 5;
				++dp[i][j].second;
			}
		}
	}

	cout << min(dp[iN - 1][iN - 1].first, dp[iN - 1][iN - 1].second) << "\n";
	return 0;
}
