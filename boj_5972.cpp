#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<pair<int, int>> vecNode[50001];
int dist[50001] = { 0, };

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
				pq.push({ iTotalDist, iNextPos });
			}
		}
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
		vecNode[iS].push_back({ iE,iW });
		vecNode[iE].push_back({ iS,iW });
	}
	for (int i = 1; i <= iN; ++i)
	{
		dist[i] = 1000000000;
	}
	dijkstra(1);
	cout << dist[iN] << "\n";

	return 0;
}
