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
	return -1;
}

int main()
{
	int iN;
	cin >> iN;

	vector<pair<int, pair<int, int>>> Node;
	for (int i = 1; i <= iN; ++i)
	{
		int iWeight;
		cin >> iWeight;
		Node.push_back({ iWeight,{0,i} });
	}
	for (int i = 1; i <= iN; ++i)
	{
		for (int j = 1; j <= iN; ++j)
		{
			int iWeight;
			cin >> iWeight;
			if (i >= j) continue;
			Node.push_back({ iWeight,{i,j} });
		}
	}

	cout << kruskal(Node, iN + 1) << "\n";
	return 0;
}
