#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int matDP[16][16][2] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iR, iC;
	cin >> iR >> iC;

	vector<vector<char>> matMap(iR, vector<char>(iC));
	for (int i = 0; i < iR; i++)
	{
		for (int j = 0; j < iC; j++)
		{
			cin >> matMap[i][j];
		}
	}

	vector<vector<int>> DP(iR, vector<int>(iC, 0));
	DP[0][0] = 1;
	for (int i = 1; i < iR; ++i)
	{
		for (int j = 1; j < iC; ++j)
		{
			for (int p = i - 1; p >= 0; --p)
			{
				for (int q = j - 1; q >= 0; --q)
				{
					if (matMap[i][j] != matMap[p][q])
					{
						DP[i][j] += DP[p][q];
					}
				}
			}
		}
	}

	cout << DP[iR - 1][iC - 1] << "\n";
	return 0;
}
