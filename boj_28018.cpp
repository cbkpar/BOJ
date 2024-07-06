#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> dp(1000002, 0);
	int iN;
	cin >> iN;
	for (int i = 0; i < iN; ++i)
	{
		int iS, iE;
		cin >> iS >> iE;
		++dp[iS];
		--dp[iE + 1];
	}

	for (int i = 1; i <= 1000001; ++i)
	{
		dp[i] += dp[i-1];
	}

	int iQ;
	cin >> iQ;
	while (iQ--)
	{
		int iNum;
		cin >> iNum;
		cout << dp[iNum] << "\n";
	}
	return 0;
}
