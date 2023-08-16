#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define MOD 1000000007

using namespace std;

// 0:기본 1:스페어 2:스트라이크
int dp[11][241][3] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string strResult;
	cin >> strResult;

	dp[0][0][0] = 1;

	for (int i = 1; i <= 9; ++i)
	{
		char chFirst = strResult[i * 2 - 2];
		char chSecond = strResult[i * 2 - 1];

		if (chFirst == 'X' || chSecond == '.')
		{
			for (int j = 0; j <= (i - 1) * 20; ++j)
			{
				dp[i][j + 10][2] = (dp[i][j + 10][2] + dp[i - 1][j][0]) % MOD;
				dp[i][j + 20][2] = (dp[i][j + 20][2] + dp[i - 1][j][1]) % MOD;
				dp[i][j + 20][2] = (dp[i][j + 20][2] + dp[i - 1][j][2]) % MOD;
			}
		}
		else if (chSecond == '/')
		{
			if (chFirst == '?')
			{
				for (int k = 0; k < 10; ++k)
				{
					for (int j = 0; j <= (i - 1) * 20; ++j)
					{
						dp[i][j + 10][1] = (dp[i][j + 10][1] + dp[i - 1][j][0]) % MOD;
						dp[i][j + 10 + k][1] = (dp[i][j + 10 + k][1] + dp[i - 1][j][1]) % MOD;
						dp[i][j + 20][1] = (dp[i][j + 20][1] + dp[i - 1][j][2]) % MOD;
					}
				}
			}
			else if (chFirst == '-')
			{
				for (int j = 0; j <= (i - 1) * 20; ++j)
				{
					dp[i][j + 10][1] = (dp[i][j + 10][1] + dp[i - 1][j][0]) % MOD;
					dp[i][j + 10][1] = (dp[i][j + 10][1] + dp[i - 1][j][1]) % MOD;
					dp[i][j + 20][1] = (dp[i][j + 20][1] + dp[i - 1][j][2]) % MOD;
				}
			}
			else
			{
				for (int j = 0; j <= (i - 1) * 20; ++j)
				{
					dp[i][j + 10][1] = (dp[i][j + 10][1] + dp[i - 1][j][0]) % MOD;
					dp[i][j + 10 + (chFirst - '0')][1] = (dp[i][j + 10 + (chFirst - '0')][1] + dp[i - 1][j][1]) % MOD;
					dp[i][j + 20][1] = (dp[i][j + 20][1] + dp[i - 1][j][2]) % MOD;
				}
			}
		}
		else if (chFirst == '?' && chSecond == '?')
		{
			for (int j = 0; j <= (i - 1) * 20; ++j)
			{
				dp[i][j + 10][2] = (dp[i][j + 10][2] + dp[i - 1][j][0]) % MOD;
				dp[i][j + 20][2] = (dp[i][j + 20][2] + dp[i - 1][j][1]) % MOD;
				dp[i][j + 20][2] = (dp[i][j + 20][2] + dp[i - 1][j][2]) % MOD;
			}
			for (int k = 0; k < 10; ++k)
			{
				for (int j = 0; j <= (i - 1) * 20; ++j)
				{
					dp[i][j + 10][1] = (dp[i][j + 10][1] + dp[i - 1][j][0]) % MOD;
					dp[i][j + 10 + k][1] = (dp[i][j + 10 + k][1] + dp[i - 1][j][1]) % MOD;
					dp[i][j + 20][1] = (dp[i][j + 20][1] + dp[i - 1][j][2]) % MOD;
				}
			}
			for (int p = 0; p < 10; ++p)
			{
				for (int q = 0; q < 10 - p; ++q)
				{
					for (int j = 0; j <= (i - 1) * 20; ++j)
					{
						dp[i][j + p + q][0] = (dp[i][j + p + q][0] + dp[i - 1][j][0]) % MOD;
						dp[i][j + 2 * p + q][0] = (dp[i][j + 2 * p + q][0] + dp[i - 1][j][1]) % MOD;
						dp[i][j + 2 * p + 2 * q][0] = (dp[i][j + 2 * p + 2 * q][0] + dp[i - 1][j][2]) % MOD;;
					}
				}
			}
		}
		else if (chFirst == '?')
		{
			int q = 0;
			if (chSecond >= '1' && chSecond <= '9') q = (chSecond - '0');
			for (int p = 0; p < 10 - q; ++p)
			{
				for (int j = 0; j <= (i - 1) * 20; ++j)
				{
					dp[i][j + p + q][0] = (dp[i][j + p + q][0] + dp[i - 1][j][0]) % MOD;
					dp[i][j + 2 * p + q][0] = (dp[i][j + 2 * p + q][0] + dp[i - 1][j][1]) % MOD;
					dp[i][j + 2 * p + 2 * q][0] = (dp[i][j + 2 * p + 2 * q][0] + dp[i - 1][j][2]) % MOD;;
				}
			}
		}
		else if (chSecond == '?')
		{
			int p = 0;
			if (chFirst >= '1' && chFirst <= '9') p = (chFirst - '0');
			for (int q = 0; q < 10 - p; ++q)
			{
				for (int j = 0; j <= (i - 1) * 20; ++j)
				{
					dp[i][j + p + q][0] = (dp[i][j + p + q][0] + dp[i - 1][j][0]) % MOD;
					dp[i][j + 2 * p + q][0] = (dp[i][j + 2 * p + q][0] + dp[i - 1][j][1]) % MOD;
					dp[i][j + 2 * p + 2 * q][0] = (dp[i][j + 2 * p + 2 * q][0] + dp[i - 1][j][2]) % MOD;
				}
			}
			for (int j = 0; j <= (i - 1) * 20; ++j)
			{
				dp[i][j + 10][1] = (dp[i][j + 10][1] + dp[i - 1][j][0]) % MOD;
				dp[i][j + 10 + p][1] = (dp[i][j + 10 + p][1] + dp[i - 1][j][1]) % MOD;
				dp[i][j + 20][1] = (dp[i][j + 20][1] + dp[i - 1][j][2]) % MOD;
			}
		}
		else
		{
			int p = 0;
			if (chFirst >= '1' && chFirst <= '9') p = (chFirst - '0');
			int q = 0;
			if (chSecond >= '1' && chSecond <= '9') q = (chSecond - '0');
			for (int j = 0; j <= (i - 1) * 20; ++j)
			{
				dp[i][j + p + q][0] = (dp[i][j + p + q][0] + dp[i - 1][j][0]) % MOD;
				dp[i][j + 2 * p + q][0] = (dp[i][j + 2 * p + q][0] + dp[i - 1][j][1]) % MOD;
				dp[i][j + 2 * p + 2 * q][0] = (dp[i][j + 2 * p + 2 * q][0] + dp[i - 1][j][2]) % MOD;
			}
		}
	}
	{
		int i = 10;
		char chFirst = strResult[18];
		char chSecond = strResult[19];
		char chThird = strResult[20];

		int iFirst = 0;
		if (chFirst >= '1' && chFirst <= '9') iFirst = chFirst - '0';
		if (chFirst == 'X') iFirst = 10;

		int iSecond = 0;
		if (chSecond >= '1' && chSecond <= '9') iSecond = chSecond - '0';
		if (chSecond == 'X') iSecond = 10;
		if (chSecond == '/') iSecond = 10 - iFirst;

		int iThird = 0;
		if (chThird >= '1' && chThird <= '9') iThird = chThird - '0';
		if (chThird == 'X') iThird = 10;
		if (chThird == '/') iThird = 10 - iSecond;

		for (int j = 0; j <= (i - 1) * 20; ++j)
		{
			dp[i][j + iFirst + iSecond + iThird][0] = (dp[i][j + iFirst + iSecond + iThird][0] + dp[i - 1][j][0]) % MOD;
			dp[i][j + iFirst * 2 + iSecond + iThird][1] = (dp[i][j + iFirst * 2 + iSecond + iThird][1] + dp[i - 1][j][1]) % MOD;
			dp[i][j + iFirst * 2 + iSecond * 2 + iThird][2] = (dp[i][j + iFirst * 2 + iSecond * 2 + iThird][2] + dp[i - 1][j][2]) % MOD;
		}
	}

	int iM;
	cin >> iM;
	for (int i = 0; i < iM; ++i)
	{
		int iScore;
		cin >> iScore;

		int iAns = 0;
		for (int j = 0; j < 3; ++j)
		{
			iAns = (iAns + dp[10][iScore][j]) % MOD;
		}
		cout << iAns << (i == iM - 1 ? "\n" : " ");
	}
	return 0;
}
