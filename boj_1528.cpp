#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> vecMinsu;
	for (int i = 1; i <= 6; ++i)
	{
		int iMax = 1 << i;
		for (int j = 0; j < iMax; ++j)
		{
			int iTemp = j;
			int iNum = 0;
			for (int k = 0; k < i; ++k)
			{
				iNum *= 10;
				iNum += (iTemp & 1 ? 7 : 4);
				iTemp /= 2;
			}
			vecMinsu.push_back(iNum);
		}
	}
	sort(vecMinsu.begin(), vecMinsu.end());

	int iN;
	cin >> iN;

	vector<int> dp(iN + 1, 1000000000);
	dp[0] = 0;

	int iSize = vecMinsu.size();
	for (int i = 0; i < iSize; ++i)
	{
		for (int j = vecMinsu[i]; j <= iN; ++j)
		{
			dp[j] = min(dp[j], dp[j - vecMinsu[i]] + 1);
		}
	}
	if (dp[iN] == 1000000000)
	{
		cout << "-1\n";
	}
	else
	{
		while (iN)
		{
			for (int i = 0; i < iSize; ++i)
			{
				if (dp[iN] - dp[iN - vecMinsu[i]] == 1)
				{
					iN -= vecMinsu[i];
					cout << vecMinsu[i] << (iN == 0 ? "\n" : " ");
					break;
				}
			}
		}
	}
	return 0;
}
