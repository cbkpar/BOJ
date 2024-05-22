#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<pair<int, int>> vecNode[1001];
int dist[1002][1002] = { 0, };

void dijkstra(int start)
{
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	pq.push({ 0, {start, 0} });

	dist[start][0] = 0;

	while (!pq.empty())
	{
		int iDist = pq.top().first;
		int iPos = pq.top().second.first;
		int iCount = pq.top().second.second;
		pq.pop();

		if (iDist > dist[iPos][iCount]) continue;
		for (const pair<int, int>& Node : vecNode[iPos])
		{
			int iNextPos = Node.first;
			int iTotalDist = iDist + Node.second;
			if (iTotalDist < dist[iNextPos][iCount + 1])
			{
				dist[iNextPos][iCount + 1] = iTotalDist;
				pq.push({ iTotalDist, {iNextPos, iCount + 1 } });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM, iK;
	cin >> iN >> iM >> iK;

	int iStart, iEnd;
	cin >> iStart >> iEnd;

	while (iM--)
	{
		int iS, iE, iW;
		cin >> iS >> iE >> iW;
		vecNode[iS].push_back({ iE,iW });
		vecNode[iE].push_back({ iS,iW });
	}
	for (int i = 0; i <= iN; ++i)
	{
		for (int j = 0;j <= iN;++j)
		{
			dist[i][j] = 1000000000;
		}
	}
	dijkstra(iStart);

	int iTax = 0;
	for (int i = 0;i <= iK;++i)
	{
		if (i > 0)
		{
			int iAmount;
			cin >> iAmount;
			iTax += iAmount;
		}

		int iAns = dist[iEnd][0];
		for (int j = 1;j <= iN;++j)
		{
			iAns = min(iAns, dist[iEnd][j] + iTax * j);
		}
		cout << iAns << "\n";
	}

	return 0;
}
