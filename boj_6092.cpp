#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> dp(13, 1000000000);
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 3;

	for (int i = 3; i <= 12; ++i)
	{
		for (int j = 1; j < i; ++j)
		{
			dp[i] = min(dp[i], dp[j] * 2 + (1 << (i - j)) - 1);
		}
	}

	for (int i = 1; i <= 12; ++i)
	{
		cout << dp[i] << "\n";
	}
	return 0;
}
