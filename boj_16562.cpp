#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find(vector<int>& parent, int vertex) {
	if (parent[vertex] == vertex) return vertex;
	return parent[vertex] = find(parent, parent[vertex]);
}

void union_vertices(vector<int>& parent, vector<int>& vecCost, int u, int v) {
	u = find(parent, u);
	v = find(parent, v);
	if (u != v)
	{
		vecCost[v] = min(vecCost[v], vecCost[u]);
		parent[u] = v;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM, iK;
	cin >> iN >> iM >> iK;
	vector<int> vecCost(iN, 0);
	for (int i = 0; i < iN; ++i) cin >> vecCost[i];
	vector<int> vecParent(iN, 0);
	for (int i = 0; i < iN; ++i) vecParent[i] = i;

	while (iM--)
	{
		int iS, iE;
		cin >> iS >> iE;
		union_vertices(vecParent, vecCost, iS - 1, iE - 1);
	}

	int iCost = 0;
	vector<bool> vecVisited(iN, false);
	for (int i = 0; i < iN; ++i)
	{
		int iNum = find(vecParent, i);
		if (!vecVisited[iNum])
		{
			vecVisited[iNum] = true;
			iCost += vecCost[iNum];
		}
	}
	if (iCost <= iK)
	{
		cout << iCost << "\n";
	}
	else
	{
		cout << "Oh no\n";
	}
	return 0;
}
