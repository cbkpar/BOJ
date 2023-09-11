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

	vector<int> vecNum(iN, 0);
	for (int i = 0; i < iN; ++i) cin >> vecNum[i];

	vector<int> dp(iN, 0);
	for (int i = 1; i < iN; ++i)
	{
		int iMax = vecNum[i];
		int iMin = vecNum[i];
		for (int j = i - 1; j >= 0; --j)
		{
			dp[i] = max(dp[i], dp[j] + (iMax - iMin));
			iMax = max(iMax, vecNum[j]);
			iMin = min(iMin, vecNum[j]);
		}
		dp[i] = max(dp[i], (iMax - iMin));
	}
	cout << dp[iN - 1] << "\n";
	return 0;
}
