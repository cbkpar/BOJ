#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int matCount[1001][31][2] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT, iW;
	cin >> iT >> iW;

	matCount[0][0][1] = -9999999;

	for (int t = 1; t <= iT; ++t)
	{
		int iNum;
		cin >> iNum;

		if (iNum == 1)
		{
			matCount[t][0][0] = matCount[t - 1][0][0] + 1;
			matCount[t][0][1] = matCount[t - 1][0][1];
			for (int i = 1; i <= iW; ++i)
			{
				matCount[t][i][0] = max(matCount[t - 1][i][0], matCount[t - 1][i - 1][1]) + 1;
				matCount[t][i][1] = max(matCount[t - 1][i - 1][0], matCount[t - 1][i][1]);
			}
		}
		else
		{
			matCount[t][0][0] = matCount[t - 1][0][0];
			matCount[t][0][1] = matCount[t - 1][0][1] + 1;
			for (int i = 1; i <= iW; ++i)
			{
				matCount[t][i][0] = max(matCount[t - 1][i][0], matCount[t - 1][i - 1][1]);
				matCount[t][i][1] = max(matCount[t - 1][i - 1][0], matCount[t - 1][i][1]) + 1;
			}
		}
	}

	int iMax = 0;
	for (int i = 0; i <= iW; ++i) iMax = max(iMax, max(matCount[iT][i][0], matCount[iT][i][1]));
	cout << iMax << "\n";

	return 0;
}
