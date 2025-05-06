#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int parent[100001][17];
int depth[100001];
long long dist[100001];

void dfs(const vector<vector<pair<int, long long>>>& Node, int iNow, int iParent)
{
	for (const pair<int, long long>& pNode : Node[iNow])
	{
		if (pNode.first == iParent) continue;

		parent[pNode.first][0] = iNow;
		depth[pNode.first] = depth[iNow] + 1;
		dist[pNode.first] = dist[iNow] + pNode.second;

		dfs(Node, pNode.first, iNow);
	}
}

void MakeLCA(int iN)
{
	for (int j = 1; j < 17; ++j)
	{
		for (int i = 1; i <= iN; ++i)
		{
			if (parent[i][j - 1] != 0)
			{
				parent[i][j] = parent[parent[i][j - 1]][j - 1];
			}
		}
	}
}

int GetLCA(int iU, int iV)
{
	if (depth[iU] < depth[iV]) swap(iU, iV);

	for (int i = 16; i >= 0; --i)
	{
		if (depth[iU] - (1 << i) >= depth[iV])
		{
			iU = parent[iU][i];
		}
	}

	if (iU == iV) return iU;

	for (int i = 16; i >= 0; --i)
	{
		if (parent[iU][i] != 0 && parent[iU][i] != parent[iV][i])
		{
			iU = parent[iU][i];
			iV = parent[iV][i];
		}
	}

	return parent[iU][0];
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	vector<vector<pair<int, long long>>> vecNode(iN + 1, vector<pair<int, long long>>());
	for (int i = 0; i < iN - 1; ++i)
	{
		int iS, iE, iW;
		cin >> iS >> iE >> iW;

		vecNode[iS].push_back({ iE,iW });
		vecNode[iE].push_back({ iS,iW });
	}

	dfs(vecNode, 1, -1);
	MakeLCA(iN);

	int iM;
	cin >> iM;
	while (iM-- > 0)
	{
		int iCommand;
		cin >> iCommand;

		if (iCommand == 1)
		{
			int iU, iV;
			cin >> iU >> iV;

			int iLCA = GetLCA(iU, iV);
			long long lDist = dist[iU] + dist[iV] - 2 * dist[iLCA];
			cout << lDist << "\n";
		}
		else if (iCommand == 2)
		{
			int iU, iV, iK;
			cin >> iU >> iV >> iK;

			int iLCA = GetLCA(iU, iV);

			if (depth[iU] - depth[iLCA] + 1 >= iK)
			{
				int iDiff = iK - 1;
				int iAns = iU;
				for (int i = 16; i >= 0; --i)
				{
					if (iDiff >= (1 << i))
					{
						iDiff -= (1 << i);
						iAns = parent[iAns][i];
					}
				}
				cout << iAns << "\n";
			}
			else
			{
				int iDiff = (depth[iV] - depth[iLCA]) - (iK - (depth[iU] - depth[iLCA] + 1));
				int iAns = iV;
				for (int i = 16; i >= 0; --i)
				{
					if (iDiff >= (1 << i))
					{
						iDiff -= (1 << i);
						iAns = parent[iAns][i];
					}
				}
				cout << iAns << "\n";
			}
		}
	}

	return 0;
}
