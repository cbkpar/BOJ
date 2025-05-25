#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool Bipartite(const vector<vector<int>>& Node, vector<bool>& Visited, vector<int>& Next, int now)
{
	for (int next : Node[now])
	{
		if (Visited[next]) continue;
		Visited[next] = true;

		if (Next[next] == -1 || Bipartite(Node, Visited, Next, Next[next]))
		{
			Next[next] = now;
			return true;
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;
	vector<vector<int>> matMap(iN, vector<int>(iN, 0));

	int iM;
	cin >> iM;
	for (int i = 0; i < iM; ++i)
	{
		int iR, iC;
		cin >> iR >> iC;
		matMap[iR - 1][iC - 1] = 1;
	}

	vector<vector<int>> matRotateMap(iN * 2 - 1, vector<int>(iN * 2 - 1, 1));
	for (int i = 0; i < iN * 2 - 1; ++i)
	{
		for (int j = 0; j < iN * 2 - 1; ++j)
		{
			if (abs(i - (iN - 1)) + abs(j - (iN - 1)) < iN)
			{
				matRotateMap[i][j] = 0;
			}
		}
	}
	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iN; ++j)
		{
			if (matMap[i][j] == 0) continue;
			int iR = i - j + iN - 1;
			int iC = i + j;
			matRotateMap[iR][iC] = 1;
		}
	}

	vector<vector<pair<int, int>>> matRotateMapOrder(iN * 2 - 1, vector<pair<int, int>>(iN * 2 - 1, { 0,0 }));
	int iIndexR = 0;
	bool bNewR = true;
	for (int i = 0; i < 2 * iN - 1; ++i)
	{
		bNewR = true;
		for (int j = 0; j < 2 * iN - 1; ++j)
		{
			if (matRotateMap[j][i] == 0)
			{
				if (bNewR)
				{
					bNewR = false;
					++iIndexR;
				}
				matRotateMapOrder[j][i].first = iIndexR;
			}
			else
			{
				bNewR = true;
			}
		}
	}

	int iIndexC = 0;
	bool bNewC = true;
	for (int i = 0; i < 2 * iN - 1; ++i)
	{
		bNewC = true;
		for (int j = 0; j < 2 * iN - 1; ++j)
		{
			if (matRotateMap[i][j] == 0)
			{
				if (bNewC)
				{
					bNewC = false;
					++iIndexC;
				}
				matRotateMapOrder[i][j].second = iIndexC;
			}
			else
			{
				bNewC = true;
			}
		}
	}

	vector<vector<int>> vecNode(iIndexR + 1, vector<int>());
	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iN; ++j)
		{
			int iR = i - j + iN - 1;
			int iC = i + j;
			if (matRotateMap[iR][iC] == 1) continue;
			int iNewR = matRotateMapOrder[iR][iC].first;
			int iNewC = matRotateMapOrder[iR][iC].second;
			vecNode[iNewR].push_back(iNewC);
		}
	}

	for (int i = 0; i <= iIndexR; ++i)
	{
		sort(vecNode[i].begin(), vecNode[i].end());
	}

	vector<int> vecNext(iIndexR + 1, -1);
	for (int i = 0; i < iIndexR + 1; ++i)
	{
		vector<bool> vecVisited(iIndexR + 1, false);
		Bipartite(vecNode, vecVisited, vecNext, i);
	}

	int iAns = 0;
	for (int i = 0; i < iIndexR + 1; ++i)
	{
		if (vecNext[i] >= 0)
		{
			++iAns;
		}
	}

	cout << iAns << "\n";
	return 0;
}
