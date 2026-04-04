#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	int iN, iK;
	cin >> iN >> iK;

	string strWord;
	cin >> strWord;

	vector<vector<int>> vecPos(26, vector<int>());
	for (int i = 'A';i <= 'Z';++i)
	{
		if (i == 'X') continue;
		for (int j = 0;j < iN;++j)
		{
			if (strWord[j] == i)
			{
				vecPos[i - 'A'].push_back(j);
			}
		}
	}

	vector<int> dp(iN + 1, 0);
	for (int i = 0;i < 26;++i)
	{
		int iSize = vecPos[i].size();
		for (int j = iSize - 2;j >= 0;--j)
		{
			dp[vecPos[i][j]] = max(dp[vecPos[i][j]], vecPos[i][iSize - 1] - vecPos[i][j] + 1);
		}
	}
	for (int i = iN - 1;i >= 0;--i)
	{
		dp[i] = max(dp[i], dp[i + 1]);
	}

	int iMax = 0;
	for (int i = 0;i < 26;++i)
	{
		int iSize = vecPos[i].size();
		for (int j = 1;j < iSize;++j)
		{
			int iCount = vecPos[i][j] - vecPos[i][0] + 1 + dp[vecPos[i][j] + 1];
			iMax = max(iMax, iCount);
		}
	}

	int iAns = iN - iMax;
	cout << iAns << "\n";

	return 0;
}
