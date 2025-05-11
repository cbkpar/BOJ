#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int depth[100001];
int parent[100001][17];
int distMin[100001][17];
int distMax[100001][17];

void dfs(const vector<vector<pair<int, int>>>& Node, int iNow, int iParent)
{
	for (const pair<int, int>& pNode : Node[iNow])
	{
		if (pNode.first == iParent) continue;

		depth[pNode.first] = depth[iNow] + 1;
		parent[pNode.first][0] = iNow;
		distMin[pNode.first][0] = pNode.second;
		distMax[pNode.first][0] = pNode.second;

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
				distMin[i][j] = min(distMin[parent[i][j - 1]][j - 1], distMin[i][j-1]);
				distMax[i][j] = max(distMax[parent[i][j - 1]][j - 1], distMax[i][j-1]);
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

	vector<vector<pair<int, int>>> vecNode(iN + 1, vector<pair<int, int>>());
	for (int i = 0; i < iN - 1; ++i)
	{
		int iS, iE, iW;
		cin >> iS >> iE >> iW;

		vecNode[iS].push_back({ iE, iW });
		vecNode[iE].push_back({ iS, iW });
	}

	dfs(vecNode, 1, -1);
	MakeLCA(iN);

	int iK;
	cin >> iK;

	while (iK-- > 0)
	{
		int iU, iV;
		cin >> iU >> iV;
		int iLCA = GetLCA(iU, iV);

		int iMinDist = 1e9;
		int iMaxDist = 0;

		int iDiffU = depth[iU] - depth[iLCA];
		int iDiffV = depth[iV] - depth[iLCA];

		for (int i = 16; i >= 0; --i)
		{
			if (iDiffU >= (1 << i))
			{
				iDiffU -= (1 << i);
				iMinDist = min(iMinDist, distMin[iU][i]);
				iMaxDist = max(iMaxDist, distMax[iU][i]);
				iU = parent[iU][i];
			}
			if (iDiffV >= (1 << i))
			{
				iDiffV -= (1 << i);
				iMinDist = min(iMinDist, distMin[iV][i]);
				iMaxDist = max(iMaxDist, distMax[iV][i]);
				iV = parent[iV][i];
			}
		}
		cout << iMinDist << " " << iMaxDist << "\n";
	}

	return 0;
}
