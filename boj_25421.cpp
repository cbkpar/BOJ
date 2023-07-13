#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;
	vector<vector<int>> dp(iN, vector<int>(10, 0));
	for (int i = 1; i <= 9; ++i) dp[0][i] = 1;

	for (int i = 1; i < iN; ++i)
	{
		for (int j = 1; j <= 9; ++j)
		{
			for (int k = -2; k <= 2; ++k)
			{
				if (j + k <= 0 || j + k > 9) continue;
				dp[i][j] = (dp[i][j]+dp[i - 1][j + k])%987654321;
			}
		}
	}
	int iAns = 0;
	for (int i = 1; i <= 9; ++i)
	{
		iAns = (iAns + dp[iN - 1][i]) % 987654321;
	}
	cout << iAns << "\n";
	return 0;
}
