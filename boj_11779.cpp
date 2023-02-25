#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int iN, iM;
vector<pair<int, int>> vecNode[1001];
int dist[1001] = { 0, };
int parent[1001] = { 0, };

void dijkstra(int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, start });

	dist[start] = 0;

	while (!pq.empty())
	{
		int iPos = pq.top().second;
		int iDist = pq.top().first;
		pq.pop();

		if (dist[iPos] < iDist) continue;
		for (pair<int, int> Node : vecNode[iPos])
		{
			int iNextPos = Node.first;
			int iTotalDist = iDist + Node.second;
			if (iTotalDist < dist[iNextPos])
			{
				dist[iNextPos] = iTotalDist;
				parent[iNextPos] = iPos;
				pq.push({ iTotalDist, iNextPos });
			}
		}
	}
}

void PrintRoute(int end)
{
	stack<int> stackRoute;
	while (parent[end] != -1)
	{
		stackRoute.push(end);
		end = parent[end];
	}
	stackRoute.push(end);
	cout << stackRoute.size() << "\n";
	while (!stackRoute.empty())
	{
		cout << (stackRoute.top() + 1);
		stackRoute.pop();
		cout << (stackRoute.empty() ? "\n" : " ");
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;

	while (iM--)
	{
		int iS, iE, iW;
		cin >> iS >> iE >> iW;
		vecNode[iS - 1].push_back({ iE - 1,iW });
	}

	for (int i = 0; i < iN; ++i)
	{
		dist[i] = 1000000000;
		parent[i] = -1;
	}

	int iStart, iEnd;
	cin >> iStart >> iEnd;
	dijkstra(iStart - 1);

	cout << dist[iEnd - 1] << "\n";
	PrintRoute(iEnd - 1);

	return 0;
}
