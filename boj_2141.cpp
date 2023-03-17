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
	vector<pair<long long, long long>> vecTown(iN);
	for (int i = 0; i < iN; ++i)
	{
		cin >> vecTown[i].first >> vecTown[i].second;
	}
	sort(vecTown.begin(), vecTown.end());

	vector<long long> dp(iN + 1, 0);
	for (int i = 1; i <= iN; ++i) dp[i] = dp[i - 1] + vecTown[i - 1].second;

	int iIndex = -1;
	for (int i = 1; i <= iN; ++i)
	{
		long long lDiff = (dp[iN] - dp[i]) - (dp[i]);
		if (lDiff <= 0)
		{
			iIndex = i;
			break;
		}
	}
	cout << vecTown[iIndex - 1].first << "\n";
	return 0;
}
