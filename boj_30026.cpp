#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find(vector<int>& parent, const int vertex) {
	if (parent[vertex] == vertex) return vertex;
	return parent[vertex] = find(parent, parent[vertex]);
}

void union_vertices(vector<int>& parent, int u, int v) {
	u = find(parent, u);
	v = find(parent, v);
	if (u != v) parent[u] = v;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	vector<int> vecParent(iN + 1, 0);
	for (int i = 1; i <= iN; ++i) vecParent[i] = i;

	vector<int> vecNum(iN + 1, 0);
	vector<int> vecReverse(iN + 1, 0);
	for (int i = 1; i <= iN; ++i)
	{
		cin >> vecNum[i];
		vecReverse[vecNum[i]] = i;
		union_vertices(vecParent, i, vecNum[i]);
	}

	int iCount = 0;
	vector<pair<int, int>> vecAns;
	for (int i = 1; i < iN; ++i)
	{
		int iS = find(vecParent, i);
		int iE = find(vecParent, i + 1);
		if (iS != iE)
		{
			++iCount;
			union_vertices(vecParent, iS, iE);
			vecAns.push_back({ vecReverse[i],vecReverse[i + 1] });
			swap(vecReverse[i], vecReverse[i + 1]);
		}
	}
	cout << iCount << " " << iCount << "\n";
	if (iCount != 0)
	{
		for (pair<int, int> pRoute : vecAns)
		{
			cout << (pRoute.first) << " " << (pRoute.second) << "\n";
		}
	}
	return 0;
}
