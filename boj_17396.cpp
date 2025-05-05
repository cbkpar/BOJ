#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<pair<int, int>> vecNode[100001];
long long dist[100001] = { 0, };
void dijkstra(int start)
{
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
	pq.push({ 0, start });

	dist[start] = 0;

	while (!pq.empty())
	{
		int iPos = pq.top().second;
		long long lDist = pq.top().first;
		pq.pop();

		if (dist[iPos] < lDist) continue;
		for (pair<int, int> Node : vecNode[iPos])
		{
			int iNextPos = Node.first;
			long long lTotalDist = lDist + Node.second;
			if (lTotalDist < dist[iNextPos])
			{
				dist[iNextPos] = lTotalDist;
				pq.push({ lTotalDist, iNextPos });
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

	vector<bool> vecSight(iN + 1, false);
	for (int i = 1; i <= iN; ++i)
	{
		int iSight;
		cin >> iSight;

		if (iSight == 1)
		{
			vecSight[i] = true;
		}
	}
	vecSight[iN] = false;

	for (int i = 0; i < iM; ++i)
	{
		int iS, iE, iW;
		cin >> iS >> iE >> iW;
		++iS;
		++iE;

		if (!vecSight[iS] && !vecSight[iE])
		{
			vecNode[iS].push_back({ iE, iW });
			vecNode[iE].push_back({ iS, iW });
		}
	}

	for (int i = 1; i <= iN; ++i)
	{
		dist[i] = 1e18;
	}
	dijkstra(1);

	if (dist[iN] == 1e18)
	{
		cout << "-1" << "\n";
	}
	else
	{
		cout << dist[iN] << "\n";
	}

	return 0;
}
