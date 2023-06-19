#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;

	vector<string> matMap(iN, "");
	for (int i = 0; i < iN; ++i) cin >> matMap[i];
	vector<vector<long long>> dp(iN + 1, vector<long long>(iM + 1, 0));
	dp[1][1] = 1;
	for (int i = 1; i <= iN; ++i)
	{
		for (int j = 1; j <= iM; ++j)
		{
			if (i == 1 && j == 1) continue;
			if (matMap[i - 1][j - 1] == '.')
			{
				dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000007;
			}
		}
	}
	cout << dp[iN][iM] << "\n";
	return 0;
}
