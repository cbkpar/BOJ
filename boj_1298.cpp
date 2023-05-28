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

	vector<vector<int>> vecNode(iN + 1, vector<int>());
	while (iM--)
	{
		int iS, iE;
		cin >> iS >> iE;
		vecNode[iS].push_back(iE);
	}
	vector<int> vecNext(iN + 1, 0);
	for (int i = 1; i <= iN; ++i)
	{
		vector<bool> vecVisited(iN + 1, false);
		Bipartite(vecNode, vecVisited, vecNext, i);
	}

	int iAns = 0;
	for (int i = 1; i <= iN; ++i)
	{
		if (vecNext[i] > 0)
		{
			++iAns;
		}
	}
	cout << iAns << "\n";
	return 0;
}
