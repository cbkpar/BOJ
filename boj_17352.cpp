#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find(vector<int>& parent, int vertex) {
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

	vector<int> parent(iN + 1);
	for (int i = 0; i < iN + 1; i++) parent[i] = i;

	for (int i = 0; i < iN - 1; ++i)
	{
		int iS, iE;
		cin >> iS >> iE;
		if (find(parent, iS) != find(parent, iE)) {
			union_vertices(parent, iS, iE);
		}
	}

	vector<int> vecAns;
	for (int i = 1; i <= iN; ++i)
	{
		if (i == find(parent, i))
		{
			vecAns.push_back(i);
		}
	}

	cout << vecAns[0] << " " << vecAns[1] << "\n";

	return 0;
}
