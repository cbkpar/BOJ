#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	string strA, strB;
	cin >> strA >> strB;

	vector<vector<int>> dp(iN + 1, vector<int>(10, 999999999));
	vector<vector<int>> rotate(iN + 1, vector<int>(10, 0));
	vector<vector<int>> route(iN + 1, vector<int>(10, 0));
	dp[0][0] = 0;

	for (int i = 1; i <= iN; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			int iA = (strA[i - 1] - '0' + j) % 10;
			int iB = (strB[i - 1] - '0');

			int iLeft = (iB - iA + 10) % 10;
			int iRight = (iA - iB + 10) % 10;

			int iLeftNext = (j + iLeft) % 10;
			int iRightNext = j;

			if (dp[i - 1][j] + iLeft < dp[i][iLeftNext])
			{
				dp[i][iLeftNext] = dp[i - 1][j] + iLeft;
				rotate[i][iLeftNext] = iLeft;
				route[i][iLeftNext] = j;
			}

			if (dp[i - 1][j] + iRight < dp[i][iRightNext])
			{
				dp[i][iRightNext] = dp[i - 1][j] + iRight;
				rotate[i][iRightNext] = iRight * -1;
				route[i][iRightNext] = j;
			}
		}
	}

	int iMin = 999999999;
	for (int i = 0; i < 10; ++i)
	{
		iMin = min(iMin, dp[iN][i]);
	}

	for (int i = 0; i < 10; ++i)
	{
		if (dp[iN][i] == iMin)
		{
			cout << iMin << "\n";
			int iNextRoute = i;
			for (int j = iN; j > 0; --j)
			{
				cout << j << " " << rotate[j][iNextRoute] << "\n";
				iNextRoute = route[j][iNextRoute];
			}
			break;
		}
	}

	return 0;
}
