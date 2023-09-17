#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM, iK;
	cin >> iN >> iM >> iK;

	vector<int> vecNum(iN, 0);
	for (int i = 0; i < iN; ++i) cin >> vecNum[i];

	vector<vector<int>> dp(iM, vector<int>(iK, 0));
	for (int i = 0; i < iN; ++i)
	{
		if (vecNum[i] == 0) continue;
		++dp[0][vecNum[i] % iK];
	}
	for (int i = 0; i < iM - 1; ++i)
	{
		for (int j = 0; j < iK; ++j)
		{
			for (int k = 0; k < iN; ++k)
			{
				int iNext = (j * 10 + vecNum[k]) % iK;
				dp[i + 1][iNext] = (dp[i + 1][iNext] + dp[i][j]) % 1000000007;
			}
		}
	}
	cout << dp[iM - 1][0] << "\n";
	return 0;
}
