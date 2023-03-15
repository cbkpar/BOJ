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

	vector<vector<int>> dp(iN + 1, vector<int>(3, 0));
	dp[1][1] = 1;
	dp[1][2] = 1;
	for (int i = 2; i <= iN; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			for (int k = 0; k < 3; ++k)
			{
				dp[i][j] = (dp[i][j] + dp[i - 1][k]) % 1000000009;
			}
		}
	}
	cout << dp[iN][0] << "\n";
	return 0;
}
