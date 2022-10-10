#include <iostream>

using namespace std;

long long matMap[1001][1001] = { 0, };
long long matSum[1001][1001] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;
	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iN; ++j)
		{
			cin >> matMap[i][j];
		}
	}
	while (iM--)
	{
		int iType, iR1, iC1, iR2, iC2;
		cin >> iType >> iR1 >> iC1 >> iR2 >> iC2;
		if (iType == 1)
		{
			int iNum;
			cin >> iNum;
			matSum[iR1][iC1] += iNum;
			matSum[iR2 + 1][iC1] -= iNum;
			matSum[iR1][iC2 + 1] -= iNum;
			matSum[iR2 + 1][iC2 + 1] += iNum;
		}
		else
		{
			for (int i = 0; i < iN; ++i)
			{
				for (int j = 0; j < iN; ++j)
				{
					if (i != 0) matSum[i][j] += matSum[i - 1][j];
					if (j != 0) matSum[i][j] += matSum[i][j - 1];
					if (i != 0 && j != 0) matSum[i][j] -= matSum[i - 1][j - 1];
				}
			}
			long long lSum = 0;
			for (int i = iR1; i <= iR2; ++i)
			{
				for (int j = iC1; j <= iC2; ++j)
				{
					lSum += matSum[i][j] + matMap[i][j];
				}
			}
			cout << lSum << "\n";
		}
	}
	return 0;
}
