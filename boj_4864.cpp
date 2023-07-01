#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> dp(10001, 0);
	int iIndex = 0;
	int iSum = 1;
	int iCount = 1;
	for (int i = 1; i <= 10000; ++i)
	{
		dp[i] = dp[i - 1] + iSum;
		if (--iCount == 0)
		{
			iCount = ++iSum;
		}
	}

	while (true)
	{
		int iNum;
		cin >> iNum;
		if (iNum == 0) break;
		cout << iNum << " " << dp[iNum] << "\n";
	}
	return 0;
}
