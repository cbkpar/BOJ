#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int iN, iM;

vector<pair<int, int>> Node[5001];
int ArrDist[5001];

void dijkstra(int iStart)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, iStart });
	ArrDist[iStart] = 0;

	while (!pq.empty())
	{
		int iDist = pq.top().first;
		int iNode = pq.top().second;
		pq.pop();

		if (ArrDist[iNode] < iDist)
		{
			continue;
		}

		for (int i = 0; i < Node[iNode].size(); i++)
		{
			int iCost = iDist + Node[iNode][i].second;
			if (iCost < ArrDist[Node[iNode][i].first])
			{
				ArrDist[Node[iNode][i].first] = iCost;
				pq.push(make_pair(iCost, Node[iNode][i].first));
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> iN >> iM;
	while (iM--)
	{
		int iS, iE, iCost;
		cin >> iS >> iE >> iCost;
		--iS;
		--iE;
		Node[iS].push_back({ iE, iCost });
		Node[iE].push_back({ iS, iCost });
	}
	fill(ArrDist, ArrDist + 5001, 1000000000);
	int iStart, iEnd;
	cin >> iStart >> iEnd;
	--iStart;
	--iEnd;
	dijkstra(iStart);
	cout << ArrDist[iEnd] << "\n";
	return 0;
}
