#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<pair<long long, long long>>> vecNode(200001, vector<pair<long long, long long>>());
long long dist[200001] = { 0, };
bool bMinus = false;

void dijkstra(int start)
{
	priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
	pq.push({ 0, start });

	dist[start] = 0;

	while (!pq.empty())
	{
		int iPos = pq.top().second;
		long long iDist = pq.top().first;
		pq.pop();

		if (dist[iPos] < iDist) continue;
		for (pair<long long, long long>& Node : vecNode[iPos])
		{
			if (Node.second < 0)
			{
				Node.second = 0;
				bMinus = true;
			}

			int iNextPos = Node.first;
			long long iTotalDist = iDist + Node.second;
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
		int iS, iE;
		cin >> iS >> iE;
		long long lW1, lW2;
		cin >> lW1 >> lW2;
		long long lW = lW1 + lW2;
		vecNode[iS].push_back({ iE,lW });
		vecNode[iE].push_back({ iS,lW });
	}

	long long lT;
	cin >> lT;
	lT *= 2;

	for (int i = 1; i <= iN; ++i)
	{
		dist[i] = 10000000000000000L;
	}
	dijkstra(1);

	int iAns = 0;
	vector<int> vecAns;
	if (bMinus)
	{
		for (int i = 2;i <= iN;++i)
		{
			if (dist[i] != 10000000000000000L)
			{
				++iAns;
				vecAns.push_back(i);
			}
		}
	}
	else
	{
		for (int i = 2;i <= iN;++i)
		{
			if (dist[i] <= lT)
			{
				++iAns;
				vecAns.push_back(i);
			}
		}
	}

	cout << iAns << "\n";
	for (int i = 0;i < iAns;++i)
	{
		cout << vecAns[i] << (i == iAns - 1 ? "\n" : " ");
	}
	return 0;
}
