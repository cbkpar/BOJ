#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iC;
	cin >> iN >> iC;

	vector<int> dp(iN + 1);
	dp[0] = 1;

	for (int i = 1; i <= iC; ++i)
	{
		int iCent;
		cin >> iCent;

		for (int j = iCent; j <= iN; ++j)
		{
			dp[j] += dp[j - iCent];
		}
	}
	cout << dp[iN] << "\n";
	return 0;
}
