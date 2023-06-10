#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int DateToInt(const string& date)
{
	int iRet = 0;
	for (int i = 0; i < 4; ++i)
	{
		iRet *= 10;
		iRet += date[i] - '0';
	}
	iRet *= 12;
	iRet += (date[5] - '0') * 10 + (date[6] - '0');
	--iRet;
	return iRet;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> dp(120001, 0);

	int iN;
	cin >> iN;
	while (iN--)
	{
		string strStart, strEnd;
		cin >> strStart >> strEnd;

		int iS = DateToInt(strStart);
		int iE = DateToInt(strEnd);
		++dp[iS];
		--dp[iE + 1];
	}
	for (int i = 1; i <= 120000; ++i)
	{
		dp[i] += dp[i - 1];
	}
	int iAns = -1;
	int iMax = -1;
	for (int i = 0; i <= 120000; ++i)
	{
		if (dp[i] > iMax)
		{
			iMax = dp[i];
			iAns = i;
		}
	}
	printf("%04d-%02d\n", (iAns / 12), ((iAns % 12) + 1));
	return 0;
}
