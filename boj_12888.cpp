#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long dp[61][2] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	dp[0][0] = 1;
	for (int i = 1;i <= 60;++i)
	{
		dp[i][0] = dp[i - 1][1] * 2;
		dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
	}

	int iH;
	cin >> iH;

	cout << (dp[iH][0] + dp[iH][1]) << "\n";
	return 0;
}
