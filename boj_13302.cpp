#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[101][41] = { 0, };
bool Visited[101] = { false, };

int main()
{
	int iN, iM;
	cin >> iN >> iM;
	while (iM--)
	{
		int iDay;
		cin >> iDay;
		Visited[iDay] = true;
	}
	for (int i = 1; i <= 40; ++i) dp[0][i] = 1000000000;
	for (int i = 1; i <= iN; ++i)
	{
		if (Visited[i])
		{
			for (int j = 0; j <= 40; ++j)
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
		else
		{
			for (int j = 0; j <= 40; ++j)
			{
				dp[i][j] = dp[i - 1][j] + 10000;
				for (int k = 1; k <= 3; ++k)
				{
					if (i >= k && j >= 1) dp[i][j] = min(dp[i][j], dp[i - k][j - 1] + 25000);
				}
				for (int k = 1; k <= 5; ++k)
				{
					if (i >= k && j >= 2) dp[i][j] = min(dp[i][j], dp[i - k][j - 2] + 37000);
				}
				if (j <= 37) dp[i][j] = min(dp[i][j], dp[i - 1][j + 3]);
			}
		}
	}
	int iAns = 1000000000;
	for (int i = 0; i <= 40; ++i) iAns = min(iAns, dp[iN][i]);
	cout << iAns << "\n";
	return 0;
}
