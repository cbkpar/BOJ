#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

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

int kruskal(vector<pair<int, pair<int, int>>>& edges, int n) {
	vector<int> parent(n);
	for (int i = 0; i < n; i++) parent[i] = i;

	int iCount = 0;
	int iSum = 0;

	sort(edges.begin(), edges.end());
	for (auto edge : edges) {
		int weight = edge.first;
		int u = edge.second.first;
		int v = edge.second.second;
		if (find(parent, u) != find(parent, v)) {
			iSum += edge.first;
			union_vertices(parent, u, v);
			++iCount;
			if (iCount == n - 1)
			{
				return iSum;
			}
		}
	}
	return 0;
}

int main()
{
	while (true)
	{
		int iN;
		cin >> iN;
		if (iN == 0) break;
		vector<pair<int, pair<int, int>>> Node;
		string s, e;
		for (int i = 0; i < iN - 1; ++i)
		{
			cin >> s;
			int iM, iWeight;
			cin >> iM;
			while (iM--)
			{
				cin >> e >> iWeight;
				Node.push_back({ iWeight,{s[0] - 'A',e[0] - 'A'} });
			}
		}
		cout << kruskal(Node, iN) << "\n";
	}

	return 0;
}
