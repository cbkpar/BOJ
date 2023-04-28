#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int matMap[5][5] = { 0, };
bool Visited[5][5] = { false, };
bool bPossible = false;

int dR[4] = { -1,0,1,0 };
int dC[4] = { 0,-1,0,1 };

void dfs(int iR, int iC, int iK, int iSum)
{
	if (iK == 3)
	{
		if (iSum >= 2)
		{
			bPossible = true;
		}
		return;
	}
	for (int i = 0; i < 4; ++i)
	{
		int iNextR = iR + dR[i];
		int iNextC = iC + dC[i];

		if (iNextR < 0 || iNextR >= 5 || iNextC < 0 || iNextC >= 5) continue;
		if (Visited[iNextR][iNextC]) continue;
		if (matMap[iNextR][iNextC] >= 0)
		{
			Visited[iNextR][iNextC] = true;
			dfs(iNextR, iNextC, iK + 1, iSum + matMap[iNextR][iNextC]);
			Visited[iNextR][iNextC] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			cin >> matMap[i][j];
		}
	}
	int iR, iC;
	cin >> iR >> iC;
	Visited[iR][iC] = true;
	dfs(iR, iC, 0, matMap[iR][iC]);

	if (bPossible)
	{
		cout << "1\n";
	}
	else
	{
		cout << "0\n";
	}
	return 0;
}
