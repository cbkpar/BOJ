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

	string strWord;
	cin >> strWord;

	int iSize = strWord.length();

	vector<vector<long long>> dp(iSize, vector<long long>(8, 0));
	if (strWord[0] == 'L')
	{
		dp[0][6] = 1;

	}
	else if (strWord[0] == '_')
	{
		dp[0][0] = 5;
		dp[0][2] = 20;
		dp[0][6] = 1;
	}
	else if (strWord[0] == 'A' || strWord[0] == 'E' || strWord[0] == 'I' || strWord[0] == 'O' || strWord[0] == 'U')
	{
		dp[0][0] = 1;
	}
	else
	{
		dp[0][2] = 1;
	}
	for (int i = 1; i < iSize; ++i)
	{
		if (strWord[i] == 'L')
		{
			dp[i][6] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][4] + dp[i - 1][5];
			dp[i][7] = dp[i - 1][2] + dp[i - 1][6];
		}
		else if (strWord[i] == '_')
		{
			dp[i][0] = (dp[i - 1][2] + dp[i - 1][3]) * 5;
			dp[i][1] = dp[i - 1][0] * 5;
			dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) * 20;
			dp[i][3] = dp[i - 1][2] * 20;
			dp[i][4] = (dp[i - 1][6] + dp[i - 1][7]) * 5;
			dp[i][5] = dp[i - 1][4] * 5;
			dp[i][6] = (dp[i - 1][0] + dp[i - 1][1]) + (dp[i - 1][4] + dp[i - 1][5]) * 21;
			dp[i][7] = dp[i - 1][2] + dp[i - 1][6] * 21;
		}
		else if (strWord[i] == 'A' || strWord[i] == 'E' || strWord[i] == 'I' || strWord[i] == 'O' || strWord[i] == 'U')
		{
			dp[i][0] = dp[i - 1][2] + dp[i - 1][3];
			dp[i][1] = dp[i - 1][0];
			dp[i][4] = dp[i - 1][6] + dp[i - 1][7];
			dp[i][5] = dp[i - 1][4];
		}
		else
		{
			dp[i][2] = dp[i - 1][0] + dp[i - 1][1];
			dp[i][3] = dp[i - 1][2];
			dp[i][6] = dp[i - 1][4] + dp[i - 1][5];
			dp[i][7] = dp[i - 1][6];
		}
	}
	long long lSum = 0;
	for (int i = 4; i < 8; ++i) lSum += dp[iSize - 1][i];
	cout << lSum << "\n";

	return 0;
}
