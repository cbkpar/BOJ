#include <iostream>
#include <memory.h>

using namespace std;

int main()
{
	int iN, iK;
	cin >> iN >> iK;
	long long* arrNumber = new long long[iN + 1];
	memset(arrNumber, 0, sizeof(long long)*(iN + 1));
	for (int i = 1; i <= iN; ++i)
	{
		cin >> arrNumber[i];
	}
	long long** dp = new long long*[iN + 1];
	for (int i = 0; i <= iN; ++i)
	{
		dp[i] = new long long[iK + 1];
		memset(dp[i], 0, sizeof(long long)* (iK + 1));
	}
	for (int i = 1; i <= iK; ++i)
	{
		dp[0][i] = -20000000000L;
	}
	for (int i = 1; i <= iN; ++i)
	{
		for (int j = 1; j <= iK; ++j)
		{

			dp[i][j] = dp[i - 1][j];
			long long lNext = dp[i - 1][j - 1] + arrNumber[i] - (j - 1);
			if (dp[i][j] < lNext)
			{
				dp[i][j] = lNext;
			}
		}
	}
	cout << dp[iN][iK] << endl;
	return 0;
	for (int i = 0; i <= iK; ++i)
	{
		delete[] dp[i];
	}
	delete[] dp;
	delete[] arrNumber;
}
