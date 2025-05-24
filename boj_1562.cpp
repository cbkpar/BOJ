#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[10][100][1024] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;
	for (int i = 1; i <= 9; ++i)
	{
		dp[i][0][1 << i] = 1;
	}

	for (int i = 0; i < iN - 1; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			if (j < 9)
			{
				for (int k = 0; k < 1024; ++k)
				{
					dp[j + 1][i + 1][k | (1 << (j + 1))] = (dp[j + 1][i + 1][k | (1 << (j + 1))] + dp[j][i][k]) % 1000000000;
				}
			}
			if (j > 0)
			{
				for (int k = 0; k < 1024; ++k)
				{
					dp[j - 1][i + 1][k | (1 << (j - 1))] = (dp[j - 1][i + 1][k | (1 << (j - 1))] + dp[j][i][k]) % 1000000000;
				}
			}
		}
	}

	int iAns = 0;
	for (int i = 0; i < 10; ++i)
	{
		iAns = (iAns + dp[i][iN - 1][1023]) % 1000000000;
	}
	cout << iAns << "\n";
	return 0;
}
