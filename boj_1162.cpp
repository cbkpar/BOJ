#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

long long dijkstra(const vector<vector<pair<int, long long>>>& vecNode, int iN, int iK)
{
	vector<vector<long long>> dist(iK + 1, vector<long long>(iN + 1, 10000000000000000LL));

	vector<priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>>>
		pq(iK + 1, priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>>());
	pq[0].push({ 0, 1 });
	dist[0][1] = 0;

	for (int i = 0; i <= iK; ++i)
	{
		while (!pq[i].empty())
		{
			int iPos = pq[i].top().second;
			long long lDist = pq[i].top().first;
			pq[i].pop();

			if (dist[i][iPos] < lDist) continue;
			for (const pair<int, long long>& Node : vecNode[iPos])
			{
				int iNextPos = Node.first;
				long long lTotalDist = lDist + Node.second;
				if (lTotalDist < dist[i][iNextPos])
				{
					dist[i][iNextPos] = lTotalDist;
					pq[i].push({ lTotalDist, iNextPos });
				}
				if (i < iK && lDist < dist[i + 1][iNextPos])
				{
					dist[i + 1][iNextPos] = lDist;
					pq[i + 1].push({ lDist, iNextPos });
				}
			}
		}
	}

	long long lRet = 10000000000000000LL;
	for (int i = 0; i <= iK; ++i)
	{
		lRet = min(lRet, dist[i][iN]);
	}
	return lRet;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM, iK;
	cin >> iN >> iM >> iK;

	vector<vector<pair<int, long long>>> vecNode(iN + 1, vector<pair<int, long long>>());

	while (iM--)
	{
		int iS, iE;
		long long lCost;
		cin >> iS >> iE >> lCost;
		vecNode[iS].push_back({ iE,lCost });
		vecNode[iE].push_back({ iS,lCost });
	}

	cout << dijkstra(vecNode, iN, iK) << "\n";
	return 0;
}
