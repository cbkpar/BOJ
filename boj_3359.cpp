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
	vector<pair<int, int>> vecLen(iN + 1, { 0,0 });
	for (int i = 1; i <= iN; ++i)
	{
		cin >> vecLen[i].first >> vecLen[i].second;
	}

	vector<pair<int, int>> dp(iN + 1, { 0,0 });
	dp[1].first = vecLen[1].second;
	dp[1].second = vecLen[1].first;
	for (int i = 2; i <= iN; ++i)
	{
		dp[i].first = max(dp[i - 1].first + abs(vecLen[i].first - vecLen[i - 1].first),
			dp[i - 1].second + abs(vecLen[i].first - vecLen[i - 1].second)) + vecLen[i].second;
		dp[i].second = max(dp[i - 1].first + abs(vecLen[i].second - vecLen[i - 1].first),
			dp[i - 1].second + abs(vecLen[i].second - vecLen[i - 1].second)) + vecLen[i].first;
	}
	int iAns = max(dp[iN].first, dp[iN].second);
	cout << iAns << "\n";
	return 0;
}
