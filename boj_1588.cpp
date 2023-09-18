#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long dp[21][4][4] = { 0, };
long long ans[4] = { 0, };
long long lLeft, lRight;

void divide(int iN, int iNum, long long lS, long long lE, long long lMax)
{
	if (lE<lLeft || lS > lRight) return;
	if (lS >= lLeft && lE <= lRight)
	{
		for (int i = 1; i <= 3; ++i)
		{
			ans[i] += dp[iN][iNum][i];
		}
		return;
	}
	else
	{
		lMax /= 3;
		int iA = 0;
		int iB = 0;
		int iC = 0;
		if (iNum == 1)
		{
			iA = 1;
			iB = 3;
			iC = 2;
		}
		if (iNum == 2)
		{
			iA = 2;
			iB = 1;
			iC = 1;
		}
		if (iNum == 3)
		{
			iA = 2;
			iB = 3;
			iC = 2;
		}
		divide(iN - 1, iA, lS, lS + lMax - 1, lMax);
		divide(iN - 1, iB, lS + lMax, lS + lMax *2 - 1, lMax);
		divide(iN - 1, iC, lS + lMax * 2, lS + lMax * 3 - 1, lMax);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	dp[0][1][1] = 1;
	dp[0][2][2] = 1;
	dp[0][3][3] = 1;

	for (int i = 1; i <= 20; ++i)
	{
		for (int j = 1; j <= 3; ++j)
		{
			dp[i][j][1] = dp[i - 1][j][1] + dp[i - 1][j][2] * 2;
			dp[i][j][2] = dp[i - 1][j][1] + dp[i - 1][j][2] + dp[i - 1][j][3] * 2;
			dp[i][j][3] = dp[i - 1][j][1] + dp[i - 1][j][3];
		}
	}

	int iStart, iN;
	long long lMax = 1;
	cin >> iStart >> lLeft >> lRight >> iN;
	for (int i = 0; i < iN; ++i)
	{
		lMax *= 3;
	}

	divide(iN, iStart, 0, lMax - 1, lMax);
	cout << ans[1] << " " << ans[2] << " " << ans[3] << "\n";
	return 0;
}
