#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int matMap[7][7][7] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;

	int iAns = 0;
	while (iM--)
	{
		int iA, iB, iC;
		cin >> iA >> iB >> iC;
		matMap[iA][iB][iC] = 1;
	}

	for (int i = 1; i <= iN; ++i)
	{
		for (int j = 1; j <= iN; ++j)
		{
			for (int k = 1; k <= iN; ++k)
			{
				int iCount = 0;
				iCount += matMap[i][j][k];
				iCount += matMap[i - 1][j][k];
				iCount += matMap[i + 1][j][k];
				iCount += matMap[i][j - 1][k];
				iCount += matMap[i][j + 1][k];
				iCount += matMap[i][j][k - 1];
				iCount += matMap[i][j][k + 1];
				if (iCount == 7) ++iAns;
			}
		}
	}

	cout << iAns << "\n";
	return 0;
}
