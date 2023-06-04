#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	vector<int> vecNum(iN);
	for (int i = 0; i < iN; ++i) cin >> vecNum[i];

	vector<vector<int>> dp(2, vector<int>(250001, -1));
	dp[0][0] = 0;

	int iMax = 0;
	for (int i = 0; i < iN; ++i)
	{
		iMax = min(250000, iMax + vecNum[i]);
		int iNow = i % 2;
		int iNext = (i + 1) % 2;
		for (int j = 0; j <= iMax; ++j)
		{
			if (dp[iNow][j] >= 0)
			{
				int iNextNum;
				iNextNum = j + vecNum[i];
				if (iNextNum <= 250000)
				{
					dp[iNext][iNextNum] = max(dp[iNext][iNextNum], dp[iNow][j] + vecNum[i]);
				}
				iNextNum = j - vecNum[i];
				if (iNextNum >= 0)
				{
					dp[iNext][iNextNum] = max(dp[iNext][iNextNum], dp[iNow][j]);
				}
				else
				{
					iNextNum *= -1;
					if (iNextNum <= 250000)
					{
						dp[iNext][iNextNum] = max(dp[iNext][iNextNum], dp[iNow][j] + iNextNum);
					}
				}
				dp[iNext][j] = max(dp[iNext][j], dp[iNow][j]);
			}
		}
	}
	if (dp[iN % 2][0] == 0)
	{
		cout << "-1\n";
	}
	else
	{
		cout << dp[iN % 2][0] << "\n";
	}
	return 0;
}
