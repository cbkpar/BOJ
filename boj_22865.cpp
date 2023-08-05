#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void dijkstra(int start, vector<vector<pair<int, long long>>>& vecNode, vector<long long>& vecDist)
{
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
	pq.push({ 0, start });

	vecDist[start] = 0;

	while (!pq.empty())
	{
		int iPos = pq.top().second;
		long long iDist = pq.top().first;
		pq.pop();

		if (vecDist[iPos] < iDist) continue;
		for (const pair<int, long long>& Node : vecNode[iPos])
		{
			int iNextPos = Node.first;
			long long iTotalDist = iDist + Node.second;
			if (iTotalDist < vecDist[iNextPos])
			{
				vecDist[iNextPos] = iTotalDist;
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

	int iN;
	cin >> iN;
	vector<vector<pair<int, long long>>> vecNode(iN + 1, vector<pair<int, long long>>());

	int iA, iB, iC;
	cin >> iA >> iB >> iC;

	int iM;
	cin >> iM;
	while (iM--)
	{
		int iS, iE;
		long long lCost;
		cin >> iS >> iE >> lCost;
		vecNode[iS].push_back({ iE, lCost });
		vecNode[iE].push_back({ iS, lCost });
	}
	vector<long long> vecDistA(iN + 1, 1000000000000LL);
	vector<long long> vecDistB(iN + 1, 1000000000000LL);
	vector<long long> vecDistC(iN + 1, 1000000000000LL);
	dijkstra(iA, vecNode, vecDistA);
	dijkstra(iB, vecNode, vecDistB);
	dijkstra(iC, vecNode, vecDistC);

	long long lMaxDist = -1;
	int iAns = -1;
	for (int i = 1; i <= iN; ++i)
	{
		long long lMinDist = vecDistA[i];
		lMinDist = min(lMinDist, vecDistB[i]);
		lMinDist = min(lMinDist, vecDistC[i]);
		if (lMinDist == 1000000000000LL) continue;
		if (lMinDist > lMaxDist)
		{
			iAns = i;
			lMaxDist = lMinDist;
		}
	}

	cout << iAns << "\n";
	return 0;
}
