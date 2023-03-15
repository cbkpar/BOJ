#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iT;
	cin >> iN >> iT;

	vector<int> dp(iT + 1, 0);

	while (iN--)
	{
		int iK, iS;
		cin >> iK >> iS;

		for (int i = iT; i >= iK; --i)
		{
			dp[i] = max(dp[i], dp[i - iK] + iS);
		}
	}
	int iAns = 0;
	for (int i = 0; i <= iT; ++i) iAns = max(iAns, dp[i]);
	cout << iAns << "\n";

	return 0;
}
