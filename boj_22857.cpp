#include <iostream>

#define Max(a,b) (a>b)?a:b;

using namespace std;

int dp[50001][101];
bool bIsEven[50001];

int main()
{
	int iN;
	int iK;
	cin >> iN >> iK;
	for (int i = 1; i <= iN; ++i)
	{
		int iNumber;
		cin >> iNumber;
		if (0 == iNumber % 2)
		{
			bIsEven[i] = true;
		}
	}
	int iAnswer = 0;
	for (int i = 1; i <= iN; ++i)
	{
		if (bIsEven[i])
		{
			for (int j = 0; j <= iK; ++j)
			{
				dp[i][j] = dp[i - 1][j] + 1;
			}
		}
		else
		{
			for (int j = 1; j <= iK; ++j)
			{
				//지웠을 경우
				dp[i][j] = dp[i - 1][j - 1];
				// 안지웠을 경우
				iAnswer = Max(iAnswer, dp[i - 1][j]);
			}

		}
	}
	for (int i = 0; i <= iK; ++i)
	{
		iAnswer = Max(iAnswer, dp[iN][i]);
	}
	cout << iAnswer << endl;
	return 0;
}
