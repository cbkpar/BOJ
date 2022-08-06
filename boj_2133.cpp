#include <iostream>

using namespace std;

int main()
{
	long long dp[31] = { 0, };
	dp[0] = 1;
	dp[2] = 3;
	for (int i = 4; i <= 30; i += 2)
	{
		dp[i] = dp[i - 2] * 3;
		for (int j = i - 4; j >= 0; j -= 2)
		{
			dp[i] += dp[j] * 2;
		}
	}
	int iN;
	cin >> iN;
	cout << dp[iN] << endl;
	return 0;
}
