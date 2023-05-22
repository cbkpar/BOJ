#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int iAns = 0;
int iN, iM;
int matProgress[2][3] = { 0, };

void dfs(int iDay, int iScore, int iBefore)
{
	if (iDay == iN)
	{
		if (iScore >= iM)
		{
			++iAns;
		}
		return;
	}
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (iBefore == j)
			{
				dfs(iDay + 1, iScore + matProgress[i][j] / 2, j);
			}
			else
			{
				dfs(iDay + 1, iScore + matProgress[i][j], j);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> iN >> iM;
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cin >> matProgress[i][j];
		}
	}
	dfs(0, 0, -1);
	cout << iAns << "\n";
	return 0;
}
