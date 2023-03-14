#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long dp[129][129] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iK, iN;

	cin >> iK >> iN;
	if (iK == 0)
	{
		cout << "0\n";
		return 0;
	}
	dp[0][iK] = 1;
	for (int i = 1; i <= iN; ++i)
	{
		for (int j = 1; j <= 127; ++j)
		{
			dp[i][j] += dp[i - 1][j - 1];
			dp[i][j] += dp[i - 1][j + 1];
		}
	}
	long long lAns = 0;
	for (int i = 1; i <= 128; ++i) lAns += dp[iN][i];
	cout << lAns << "\n";
	return 0;
}
