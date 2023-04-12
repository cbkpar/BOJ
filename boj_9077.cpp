#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	while (iT--)
	{
		vector<vector<int>> matMine(10001, vector<int>());
		int iN;
		cin >> iN;
		while (iN--)
		{
			int iR, iC;
			cin >> iR >> iC;
			matMine[iR].push_back(iC);
		}
		vector<int> dp(10001, 0);
		for (int i = 0; i <= 10; ++i)
		{
			for (int iNum : matMine[i])
			{
				++dp[iNum];
			}
		}
		int iAns = 0;
		{
			int iCount = 0;
			for (int i = 0; i <= 10; ++i)
			{
				iCount += dp[i];
			}
			iAns = max(iAns, iCount);
			for (int i = 11; i <= 10000; ++i)
			{
				iCount -= dp[i - 11];
				iCount += dp[i];
				iAns = max(iAns, iCount);
			}
		}
		for (int i = 11; i <= 10000; ++i)
		{
			for (int iNum : matMine[i])
			{
				++dp[iNum];
			}
			for (int iNum : matMine[i - 11])
			{
				--dp[iNum];
			}
			int iCount = 0;
			for (int j = 0; j <= 10; ++j)
			{
				iCount += dp[j];
			}
			iAns = max(iAns, iCount);
			for (int j = 11; j <= 10000; ++j)
			{
				iCount -= dp[j - 11];
				iCount += dp[j];
				iAns = max(iAns, iCount);
			}
		}
		cout << iAns << "\n";
	}
	return 0;
}
