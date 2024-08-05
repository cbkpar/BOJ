#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int dp[3001][2] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string strWord;
	cin >> strWord;

	dp[0][1] = 999999;

	int iLen = strWord.length();
	for (int i = 1;i <= iLen;++i)
	{
		if (strWord[i - 1] >= 'a' && strWord[i - 1] <= 'z')
		{
			dp[i][0] = min(dp[i - 1][0] + 1, dp[i - 1][1] + 2);
			dp[i][1] = min(dp[i - 1][1] + 2, dp[i - 1][0] + 2);
		}
		else
		{
			dp[i][0] = min(dp[i - 1][0] + 2, dp[i - 1][1] + 2);
			dp[i][1] = min(dp[i - 1][1] + 1, dp[i - 1][0] + 2);
		}
	}

	cout << min(dp[iLen][0], dp[iLen][1]) << "\n";
	return 0;
}
