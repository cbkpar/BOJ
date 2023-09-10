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

	int iN, iM;
	cin >> iN >> iM;

	for (int i = 0; i <= iN; ++i)
	{
		for (int j = 0; j <= iM; ++j)
		{
			for (int k = 0; k < 2; ++k)
			{
				dp[i][j][k] = -1000000000;
			}
		}
	}
	dp[0][0][0] = 0;
	for (int i = 1; i <= iN; ++i)
	{
		int iNum;
		cin >> iNum;

		dp[i][0][0] = 0;
		for (int j = 1; j <= iM; ++j)
		{
			dp[i][j][0] = max(dp[i - 1][j][1], dp[i - 1][j][0]);
			dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0]) + iNum;
		}
	}
	cout << max(dp[iN][iM][0], dp[iN][iM][1]) << "\n";
	return 0;
}
