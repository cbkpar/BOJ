#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool vecLeftTop[19] = { false, };
bool vecLeftBottom[19] = { false, };
int matMap[10][10] = { 0, };
int iN;
int iAns = 0;

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

	cin >> iN;
	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iN; ++j)
		{
			cin >> matMap[i][j];
		}
	}

	vector<vector<int>> vecNode(2 * iN - 1, vector<int>());
	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iN; ++j)
		{
			if (matMap[i][j] == 0) continue;
			int iR = i - j + iN - 1;
			int iC = i + j;
			vecNode[iR].push_back(iC);
		}
	}
	for (int i = 0; i < iN * 2 - 1; ++i)
	{
		sort(vecNode[i].begin(), vecNode[i].end());
	}

	vector<int> vecNext(2 * iN - 1, -1);
	for (int i = 0; i < 2 * iN - 1; ++i)
	{
		vector<bool> vecVisited(2 * iN - 1, false);
		Bipartite(vecNode, vecVisited, vecNext, i);
	}

	int iAns = 0;
	for (int i = 0; i < 2 * iN - 1; ++i)
	{
		if (vecNext[i] >= 0)
		{
			++iAns;
		}
	}

	cout << iAns << "\n";
	return 0;
}
