#include <iostream>

using namespace std;

int matDist[16][16] = { 0, };
int matDP[16][65536] = { 0, };
int iN;
int iMax;

int tsp(int k, int chk)
{
	if (chk == iMax)
	{
		if (matDist[k][0] == 0) return 20000000;
		return matDist[k][0];
	}
	if (matDP[k][chk] != 0) return matDP[k][chk];
	matDP[k][chk] = 20000000;
	for (int i = 0; i < iN; i++) {
		if (matDist[k][i] == 0 || (chk & (1 << i)) != 0) continue;
		int iCost = tsp(i, chk | (1 << i)) + matDist[k][i];
		if (iCost < matDP[k][chk])
		{
			matDP[k][chk] = iCost;
		}
	}
	return matDP[k][chk];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> iN;
	iMax = (1 << iN) - 1;

	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iN; ++j)
		{
			cin >> matDist[i][j];
		}
	}
	cout << tsp(0, 1) << "\n";
	return 0;
}
