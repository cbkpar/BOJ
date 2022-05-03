#include <iostream>

using namespace std;

int dp[301][301];
bool candy[301][301];

int main()
{
	int iN, iM;
	cin >> iN >> iM;
	for (int i = 0; i < iN; ++i)
	{
		int iX, iY;
		cin >> iX >> iY;
		candy[iX][iY] = true;
	}
	for (int i = 0; i <= 300; ++i) {
		for (int j = 0; j <= 300; ++j) {
			if (i == 0 && j == 0) continue;
			if (i == 0) {
				dp[i][j] = dp[i][j - 1];
				if (i + j < iM&&candy[i][j]) {
					dp[i][j] += iM - i - j;
				}
			}
			else if (j == 0) {
				dp[i][j] = dp[i - 1][j];
				if (i + j < iM&&candy[i][j]) {
					dp[i][j] += iM - i - j;
				}
			}
			else {
				dp[i][j] = (dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1]);
				if (i + j < iM&&candy[i][j]) {
					dp[i][j] += iM - i - j;
				}
			}
		}
	}
	cout << dp[300][300] << endl;
	return 0;
}
