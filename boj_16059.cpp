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
	vector<int> vecNum(iN + 1, 0);
	for (int i = 1;i <= iN;++i)
	{
		cin >> vecNum[i];
	}

	vector<int> dp(iN + 1, 0);
	for (int i = iM + 1;i <= iN;++i)
	{
		dp[i] = dp[i - 1];
		if (i - iM <= 0) continue;
		dp[i] = max(dp[i], dp[i - iM] + vecNum[i]);
	}

	int iAns = dp[iN];
	cout << iAns << "\n";
	return 0;
}
