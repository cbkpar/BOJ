#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;
	vector<vector<int>> dp(iN + 1, vector<int>(201, 1000000000));
	dp[1][1] = 0;
	vector<bool> vecRock(iN + 1, false);
	while (iM--)
	{
		int iPos;
		cin >> iPos;
		vecRock[iPos] = true;
	}

	for (int i = 2; i <= iN; ++i)
	{
		if (vecRock[i]) continue;
		for (int j = 1; j < 200; ++j)
		{
			for (int k = -1; k <= 1; ++k)
			{
				if (i - j - k <= 0) continue;
				dp[i][j] = min(dp[i][j], dp[i - j - k][j + k] + 1);
			}
		}
	}
	int iAns = 1000000000;
	for (int i = 1; i < 200; ++i)
	{
		iAns = min(iAns, dp[iN][i]);
	}
	if (iAns == 1000000000)
	{
		cout << "-1\n";
	}
	else
	{
		cout << iAns << "\n";
	}
	return 0;
}
