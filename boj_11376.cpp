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

		if (Next[next] == 0 || Bipartite(Node, Visited, Next, Next[next]))
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

	int iN, iM;
	cin >> iN >> iM;

	vector<vector<int>> vecNode(2 * iN + 2, vector<int>());

	for (int i = 1; i <= iN; ++i)
	{
		int iCount;
		cin >> iCount;
		for (int j = 0; j < iCount; ++j)
		{
			int iNum;
			cin >> iNum;
			vecNode[2 * i].push_back(iNum);
			vecNode[2 * i + 1].push_back(iNum);
		}
	}
	vector<int> vecNext(iM + 1, 0);
	for (int i = 1; i <= 2 * iN + 1; ++i)
	{
		vector<bool> vecVisited(iM + 1, false);
		Bipartite(vecNode, vecVisited, vecNext, i);
	}
	int iAns = 0;
	for (int i = 1; i <= iM; ++i)
	{
		if (vecNext[i] > 0) ++iAns;
	}
	cout << iAns << "\n";
	return 0;
}
