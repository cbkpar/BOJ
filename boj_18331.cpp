#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long lC;
	cin >> lC;

	int iN;
	cin >> iN;

	vector<int> vecNum(iN + 1, 0);
	for (int i = 1; i <= iN; ++i)
	{
		cin >> vecNum[i];
	}

	vector<long long> dp(iN + 1, 0);
	dp[0] = lC;
	for (int i = 1; i <= iN; ++i)
	{
		dp[i] = dp[i - 1];
		for (int j = 1; j < i; ++j)
		{
			long long lCount = dp[j] / vecNum[j];
			long long lLast = dp[j] % vecNum[j];
			dp[i] = max(dp[i], lCount * vecNum[i] + lLast);
		}
	}

	cout << dp[iN] << "\n";
	return 0;
}
