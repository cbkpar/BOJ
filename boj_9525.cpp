#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

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
	for (int i = 0; i < iN; ++i)
	{
		string strLine;
		cin >> strLine;
		for (int j = 0; j < iN; ++j)
		{
			if (strLine[j] == 'X')
			{
				matMap[i][j] = 1;
			}
		}
	}

	vector<vector<pair<int, int>>> matMapOrder(iN, vector<pair<int, int>>(iN, { 0, 0 }));
	int iIndexR = 0;
	bool bNewR = true;
	for (int i = 0; i < iN; ++i)
	{
		bNewR = true;
		for (int j = 0; j < iN; ++j)
		{
			if (matMap[j][i] == 0)
			{
				if (bNewR)
				{
					++iIndexR;
					bNewR = false;
				}
				matMapOrder[j][i].first = iIndexR;
			}
			else
			{
				bNewR = true;
			}
		}
	}

	int iIndexC = 0;
	bool bNewC = true;
	for (int i = 0; i < iN; ++i)
	{
		bNewC = true;
		for (int j = 0; j < iN; ++j)
		{
			if (matMap[i][j] == 0)
			{
				if (bNewC)
				{
					++iIndexC;
					bNewC = false;
				}
				matMapOrder[i][j].second = iIndexC;
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
			if (matMap[i][j] == 1) continue;
			int iR = matMapOrder[i][j].first;
			int iC = matMapOrder[i][j].second;
			vecNode[iR].push_back(iC);
		}
	}
	for (int i = 0; i <= iIndexR; ++i)
	{
		sort(vecNode[i].begin(), vecNode[i].end());
	}

	vector<int> vecNext(iIndexC + 1, -1);
	for (int i = 0; i <= iIndexR; ++i)
	{
		vector<bool> vecVisited(iIndexC + 1, false);
		Bipartite(vecNode, vecVisited, vecNext, i);
	}

	int iAns = 0;
	for (int i = 0; i <= iIndexC; ++i)
	{
		if (vecNext[i] >= 0)
		{
			++iAns;
		}
	}

	cout << iAns << "\n";
	return 0;
}
