#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int matAbility[11][11] = { 0, };
bool arrVisited[11] = { false, };
int iAns = 0;

void dfs(int iN, int iSum)
{
	if (iN == 11)
	{
		iAns = max(iAns, iSum);
		return;
	}
	for (int i = 0; i < 11; ++i)
	{
		if (arrVisited[i] || matAbility[iN][i] == 0) continue;
		arrVisited[i] = true;
		dfs(iN + 1, iSum + matAbility[iN][i]);
		arrVisited[i] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	while (iT--)
	{
		for (int i = 0; i < 11; ++i)
		{
			for (int j = 0; j < 11; ++j)
			{
				cin >> matAbility[i][j];
			}
		}
		for (int i = 0; i < 11; ++i)
		{
			arrVisited[i] = false;
		}
		iAns = 0;
		dfs(0, 0);
		cout << iAns << "\n";
	}
	return 0;
}
