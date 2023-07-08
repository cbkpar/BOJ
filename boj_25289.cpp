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
	vector<int> vecNum(iN, 0);
	for (int i = 0; i < iN; ++i) cin >> vecNum[i];

	vector<vector<int>> dp(101, vector<int>(201, 0));
	for (int i = 0; i < iN; ++i)
	{
		int iNow = vecNum[i];
		for (int j = 0; j <= 200; ++j)
		{
			int iDiff = j - 100;
			int iTemp = 0;
			if (iNow + iDiff > 0 && iNow + iDiff <= 100) iTemp = dp[iNow + iDiff][j];
			dp[iNow][j] = max(dp[iNow][j], iTemp + 1);
		}
	}
	int iMax = 1;
	for (int i = 0; i <= 100; ++i)
	{
		for (int j = 0; j <= 200; ++j)
		{
			iMax = max(iMax, dp[i][j]);
		}
	}
	cout << iMax << "\n";
	return 0;
}
