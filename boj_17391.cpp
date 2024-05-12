#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;

	vector<vector<int>> matWorld(iN, vector<int>(iM, 0));
	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iM; ++j)
		{
			cin >> matWorld[i][j];
		}
	}

	vector<vector<int>> matMax(iN, vector<int>(iM, 1000000000));
	matMax[0][0] = 0;
	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iM; ++j)
		{
			int iPower = matWorld[i][j];
			for (int p = 1; p <= iPower; ++p)
			{
				if (i + p > iN - 1) break;
				matMax[i + p][j] = min(matMax[i + p][j], matMax[i][j] + 1);
			}
			for (int q = 1; q <= iPower; ++q)
			{
				if (j + q > iM - 1) break;
				matMax[i][j + q] = min(matMax[i][j + q], matMax[i][j] + 1);
			}
		}
	}

	cout << matMax[iN - 1][iM - 1] << "\n";
	return 0;
}
