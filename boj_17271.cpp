#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iK;
	cin >> iN >> iK;

	vector<int> dp(iN + 1);
	for (int i = 0; i < iK; ++i) dp[i] = 1;
	for (int i = iK; i <= iN; ++i) dp[i] = (dp[i - 1] + dp[i - iK]) % 1000000007;

	cout << dp[iN] << "\n";
	return 0;
}
