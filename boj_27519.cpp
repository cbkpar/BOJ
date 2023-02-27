#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[100001] = { 0, };
bool Arrprime[100001] = { false, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 2; i * i <= 100000; i++) {
		for (int j = i * i; j <= 100000; j += i) {
			Arrprime[j] = true;
		}
	}
	vector<int> vecPrime;
	for (int i = 2; i <= 100000; ++i)
	{
		if (!Arrprime[i])
		{
			vecPrime.push_back(i);
		}
	}

	dp[0] = 1;
	int iSize = vecPrime.size();
	for (int i = 0; i < iSize; ++i)
	{
		for (int j = vecPrime[i]; j <= 100000; ++j)
		{
			dp[j] = (dp[j] + dp[j - vecPrime[i]]) % 1000000007;
		}
	}

	int iT;
	cin >> iT;

	while (iT--)
	{
		int iN;
		cin >> iN;
		cout << dp[iN] << "\n";
	}

	return 0;
}
