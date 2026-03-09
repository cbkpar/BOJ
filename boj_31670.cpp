#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	int iN;
	cin >> iN;
	vector<long long> vecR(iN + 1, 0);
	for (int i = 1;i <= iN;++i)
	{
		cin >> vecR[i];
	}

	vector<vector<long long>> dp(iN + 1, vector<long long>(2, 0));

	for (int i = 1;i <= iN;++i)
	{
		dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + vecR[i];
		dp[i][1] = dp[i - 1][0];
	}

	long long lAns = min(dp[iN][0], dp[iN][1]);
	cout << lAns << "\n";

	return 0;
}
