#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int matMap[10][10] = { 0, };
int dR[4] = { -1,0,1,0 };
int dC[4] = { 0,-1,0,1 };

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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;


	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iM; ++j)
		{
			cin >> matMap[i][j];
		}
	}

	vector<vector<int>> matIsland(iN, vector<int>(iM, 0));
	vector<vector<bool>> matVisited(iN, vector<bool>(iM, false));

	int iCount = 0;

	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iM; ++j)
		{
			if (!matVisited[i][j] && matMap[i][j] == 1)
			{
				++iCount;
				queue<pair<int, int>> qPos;
				qPos.push({ i,j });
				matIsland[i][j] = iCount;
				matVisited[i][j] = true;
				while (!qPos.empty())
				{
					pair<int, int> Pos = qPos.front();
					qPos.pop();
					for (int k = 0; k < 4; ++k)
					{
						int iNowR = Pos.first + dR[k];
						int iNowC = Pos.second + dC[k];
						if (iNowR<0 || iNowR>iN - 1 || iNowC<0 || iNowC>iM - 1) continue;
						if (matMap[iNowR][iNowC] == 0 || matVisited[iNowR][iNowC]) continue;

						qPos.push({ iNowR,iNowC });
						matIsland[iNowR][iNowC] = iCount;
						matVisited[iNowR][iNowC] = true;
					}
				}
			}
		}
	}

	vector<vector<int>> matCost(iCount, vector<int>(iCount, 1000000000));

	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iM; ++j)
		{
			if (matIsland[i][j] > 0)
			{
				for (int k = 0; k < 4; ++k)
				{
					for (int t = 1;; ++t)
					{
						int iNowR = i + dR[k] * t;
						int iNowC = j + dC[k] * t;
						if (iNowR<0 || iNowR>iN - 1 || iNowC<0 || iNowC>iM - 1) break;
						if (matIsland[iNowR][iNowC] == matIsland[i][j]) break;
						if (matIsland[iNowR][iNowC] > 0)
						{
							if (t >= 3)
							{
								matCost[matIsland[i][j] - 1][matIsland[iNowR][iNowC] - 1] = min(matCost[matIsland[i][j] - 1][matIsland[iNowR][iNowC] - 1], t - 1);
							}
							break;
						}

					}
				}
			}
		}
	}

	vector<pair<int, pair<int, int>>> Node;

	for (int i = 0; i < iCount; ++i)
	{
		for (int j = 0; j < iCount; ++j)
		{
			if (matCost[i][j] != 1000000000)
			{
				Node.push_back({ matCost[i][j],{i,j} });
			}
		}
	}

	cout << kruskal(Node, iCount) << "\n";

	return 0;
}
