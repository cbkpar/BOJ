#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	while (iT--)
	{
		int iN, iL;
		cin >> iN >> iL;
		if (iL == 1)
		{
			if (iN == 1)
			{
				cout << "1" << "\n";
			}
			else
			{
				cout << "0" << "\n";
			}
			continue;
		}
		int iSqrt = (int)sqrt(iN);
		vector<int> dp(iSqrt + 1, 0);
		for (int i = 1; i <= iSqrt; ++i)
		{
			if (i * i < iN)
			{
				dp[i] = 1;
			}
		}
		for (int i = 2; i < iL; ++i)
		{
			vector<int> vecTemp(iSqrt + 1, 0);
			for (int j = 2; j <= iSqrt; ++j)
			{
				int iTempSqrt = (int)sqrt(j);
				for (int k = 1; k <= iSqrt; ++k)
				{
					if (k * k < j)
					{
						vecTemp[k] += dp[j];
					}
				}
			}
			for (int j = 1; j <= iSqrt; ++j)
			{
				dp[j] = vecTemp[j];
			}
		}
		cout << dp[1] << "\n";
	}
	return 0;
}
