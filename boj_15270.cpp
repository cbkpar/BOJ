#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Visited[21] = { false, };
int g_iAns = 0;
int iN, iM;
vector<pair<int, int>> vecNode;


void dfs(int iNow, int iK)
{
	if (!Visited[vecNode[iNow].first] && !Visited[vecNode[iNow].second])
	{
		Visited[vecNode[iNow].first] = true;
		Visited[vecNode[iNow].second] = true;
		g_iAns = max(g_iAns, iK * 2 + 2);
		if (iNow < iM - 1)
		{
			dfs(iNow + 1, iK + 1);
		}
		Visited[vecNode[iNow].first] = false;
		Visited[vecNode[iNow].second] = false;
	}
	if (iNow < iM - 1)
	{
		dfs(iNow + 1, iK);
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> iN >> iM;
	vecNode = vector<pair<int, int>>(iM, { 0,0 });
	for (int i = 0;i < iM;++i)
	{
		cin >> vecNode[i].first >> vecNode[i].second;
	}
	if (iM != 0)
	{
		dfs(0, 0);
	}

	if (g_iAns != iN) ++g_iAns;
	cout << g_iAns << "\n";
	return 0;
}
