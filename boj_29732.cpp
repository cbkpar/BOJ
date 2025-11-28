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

	int iN, iM, iK;
	cin >> iN >> iM >> iK;

	string strLine;
	cin >> strLine;

	vector<int> dp(iN + 1, 0);
	for (int i = 0;i < iN;++i)
	{
		if (strLine[i] == 'R')
		{
			int iMin = max(i - iK, 0);
			int iMax = min(i + iK + 1, iN);
			dp[iMin]++;
			dp[iMax]--;
		}
	}

	int iCount = 0;
	for (int i = 1;i <= iN;++i)
	{
		dp[i] += dp[i - 1];
	}
	for (int i = 0;i < iN;++i)
	{
		if (dp[i] > 0) ++iCount;
	}

	if (iCount <= iM)
	{
		cout << "Yes" << "\n";
	}
	else
	{
		cout << "No" << "\n";
	}
	return 0;

}
