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

	int iN, iM, iK;
	cin >> iN >> iM >> iK;

	vector<int> parent(iN + 1);
	for (int i = 0; i <= iN; i++) parent[i] = i;

	int iCount = 0;
	while (iK--)
	{
		int iNum;
		cin >> iNum;

		union_vertices(parent, iNum, 0);
		++iCount;
	}

	int iSum = 0;
	vector<pair<int, pair<int, int>>> vecEdge(iM);
	for (int i = 0; i < iM; ++i)
	{
		cin >> vecEdge[i].second.first;
		cin >> vecEdge[i].second.second;
		cin >> vecEdge[i].first;
	}
	sort(vecEdge.begin(), vecEdge.end());
	for (const auto& edge : vecEdge) {
		int iWeight = edge.first;
		int iU = edge.second.first;
		int iV = edge.second.second;
		if (find(parent, iU) != find(parent, iV)) {
			iSum += edge.first;
			union_vertices(parent, iU, iV);
			++iCount;
			if (iCount == iN)
			{
				break;
			}
		}
	}
	cout << iSum << "\n";
	return 0;
}
