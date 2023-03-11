#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[500][500] = { 0, };
int Num[500][500] = { 0, };
int iN;

int dR[4] = { -1,0,1,0 };
int dC[4] = { 0,-1,0,1 };

int DFS(pair<int, int> Pos)
{
	if (dp[Pos.first][Pos.second] != -1) return dp[Pos.first][Pos.second];
	int iCount = 1;
	int iMax = 0;
	for (int i = 0; i < 4; ++i)
	{
		int iNextR = Pos.first + dR[i];
		int iNextC = Pos.second + dC[i];
		if (iNextR<0 || iNextR>iN - 1 || iNextC<0 || iNextC>iN - 1) continue;
		if (Num[Pos.first][Pos.second] < Num[iNextR][iNextC])
		{
			iMax = max(iMax, DFS({ iNextR,iNextC }));
		}
	}
	return dp[Pos.first][Pos.second] = iCount + iMax;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> iN;
	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iN; ++j)
		{
			dp[i][j] = -1;
			cin >> Num[i][j];
		}
	}
	int iAns = 0;
	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iN; ++j)
		{
			iAns = max(iAns, DFS({ i,j }));
		}
	}
	cout << iAns << "\n";
	return 0;
}
