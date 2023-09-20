#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;

	vector<long long> dp(1000001, 0);
	for (int i = 0; i < iN; ++i)
	{
		int iW, iV;
		cin >> iW >> iV;
		for (int i = 1000000; i >= iW; --i)
		{
			dp[i] = max(dp[i], dp[i - iW] + iV);
		}
	}
	for (int i = 1; i <= 1000000; ++i)
	{
		dp[i] = max(dp[i], dp[i - 1]);
	}

	int iAns = 1;
	long long lMaxW = 1;
	long long lMaxV = 0;
	for (int i = 1; i <= iM; ++i)
	{
		long long lW;
		cin >> lW;
		long long lV = dp[lW];

		if (lMaxV * lW < lV * lMaxW)
		{
			iAns = i;
			lMaxW = lW;
			lMaxV = lV;
		}
	}
	cout << iAns << "\n";
	return 0;
}
