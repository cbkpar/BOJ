#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool ArrPrime[100001] = { false, };



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	for (int i = 2; i * i <= iN; i++) {
		for (int j = i * i; j <= iN; j += i) {
			ArrPrime[j] = true;
		}
	}
	vector<int> vecPrime;
	for (int i = 2; i <= iN; ++i)
	{
		if (!ArrPrime[i])
		{
			vecPrime.push_back(i);
		}
	}
	vector<long long> dp(iN + 1, 0);
	dp[0] = 1;
	for (int iValue : vecPrime)
	{
		for (int i = iValue; i <= iN; ++i)
		{
			dp[i] = (dp[i] + dp[i - iValue]) % 123456789;
		}
	}
	cout << dp[iN] << "\n";
	return 0;
}
