#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;

	vector<bool> Amount(iN + 1, false);
	vector<int> dp(iN + 1, 1000000000);
	dp[0] = 0;

	vector<int> vecAmount(iM);
	for (int i = 0; i < iM; ++i) cin >> vecAmount[i];

	for (int i = 0; i < iM; ++i)
	{
		Amount[vecAmount[i]] = true;
		for (int j = 0; j < iM; ++j)
		{
			if (i == j) continue;
			int iSum = vecAmount[i] + vecAmount[j];
			if (iSum <= iN) Amount[iSum] = true;
		}
	}

	for (int i = 1; i <= iN; ++i)
	{
		if (Amount[i])
		{
			for (int j = i; j <= iN; ++j)
			{
				dp[j] = min(dp[j], dp[j - i] + 1);
			}
		}
	}

	if (dp[iN] >= 1000000000)
	{
		cout << "-1\n";
	}
	else
	{
		cout << dp[iN] << "\n";
	}
	return 0;
}
