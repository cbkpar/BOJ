#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

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

double kruskal(vector<pair<double, pair<int, int>>>& edges, int n) {
	vector<int> parent(n);
	for (int i = 0; i < n; i++) parent[i] = i;

	int iCount = 0;
	double dSum = 0;

	sort(edges.begin(), edges.end());
	for (auto edge : edges) {
		int weight = edge.first;
		int u = edge.second.first;
		int v = edge.second.second;
		if (find(parent, u) != find(parent, v)) {
			dSum += edge.first;
			union_vertices(parent, u, v);
			++iCount;
			if (iCount == n - 1)
			{
				return dSum;
			}
		}
	}
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;
	vector<pair<double, double>> vecPos(iN);
	for (int i = 0; i < iN; ++i)
	{
		cin >> vecPos[i].first >> vecPos[i].second;
	}

	vector<pair<double, pair<int, int>>> vecNode;
	while (iM--)
	{
		int iS, iE;
		cin >> iS >> iE;
		vecNode.push_back({ 0, { iS - 1,iE - 1 } });
	}
	for (int i = 0; i < iN; ++i)
	{
		for (int j = i + 1; j < iN; ++j)
		{
			double dDist = sqrt((vecPos[i].first - vecPos[j].first) * (vecPos[i].first - vecPos[j].first) + (vecPos[i].second - vecPos[j].second) * (vecPos[i].second - vecPos[j].second));
			vecNode.push_back({ dDist,{i,j} });
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << kruskal(vecNode, iN) << "\n";
	return 0;
}
