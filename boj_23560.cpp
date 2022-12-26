#include <iostream>

using namespace std;

int dp[46][3][3] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	dp[0][0][2] = 1;

	for (int i = 0; i < iN * 3; ++i)
	{
		if (i % 3 == 0 || i % 3 == 2)
		{
			for (int p = 0; p < 3; ++p)
			{
				for (int q = 0; q < 3; ++q)
				{
					if (p != 1)
					{
						dp[i + 1][(p + 1) % 3][q] += dp[i][p][q];
					}
					if (q != 1)
					{
						dp[i + 1][p][(q + 2) % 3] += dp[i][p][q];
					}
				}
			}
		}
		else
		{
			for (int p = 0; p < 3; ++p)
			{
				for (int q = 0; q < 3; ++q)
				{
					if (p == 1)
					{
						dp[i + 1][(p + 1) % 3][q] += dp[i][p][q];
					}
					if (q == 1)
					{
						dp[i + 1][p][(q + 2) % 3] += dp[i][p][q];
					}
				}
			}
		}
	}
	int iCount = 0;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			iCount += dp[iN * 3][i][j];
		}
	}
	cout << (iCount / 2) << "\n";
	return 0;
}
