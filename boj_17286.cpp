#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

vector<pair<int, int>> vecPos(4, { 0,0 });
vector<int> vecOrder(4, 0);
vector<bool> vecVisited(4, false);
long long lAns = 10000000;

void dfs(int iN)
{
	if (iN == 4)
	{
		double dAns = 0;
		for (int i = 0; i < 3; ++i)
		{
			int iS = vecOrder[i];
			int iE = vecOrder[i + 1];
			dAns += sqrt((vecPos[iS].first - vecPos[iE].first) * (vecPos[iS].first - vecPos[iE].first) + (vecPos[iS].second - vecPos[iE].second) * (vecPos[iS].second - vecPos[iE].second));
		}
		lAns = min(lAns, (long long)dAns);
		return;
	}
	for (int i = 1; i <= 3; ++i)
	{
		if (!vecVisited[i])
		{
			vecVisited[i] = true;
			vecOrder[iN] = i;
			dfs(iN + 1);
			vecVisited[i] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 4; ++i)
	{
		cin >> vecPos[i].first >> vecPos[i].second;
	}
	dfs(1);
	cout << lAns << "\n";
	return 0;
}
