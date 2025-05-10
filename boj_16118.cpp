#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<pair<int, long long>> vecNode[4001];
long long distFox[4001] = { 0, };
long long distWolf[4001][2] = { 0, };

void dijkstraFox(int start)
{
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
	pq.push({ 0, start });

	distFox[start] = 0;

	while (!pq.empty())
	{
		int iPos = pq.top().second;
		long long lDist = pq.top().first;
		pq.pop();

		if (distFox[iPos] < lDist) continue;
		for (pair<int, long long> Node : vecNode[iPos])
		{
			int iNextPos = Node.first;
			long long lTotalDist = lDist + Node.second;
			if (lTotalDist < distFox[iNextPos])
			{
				distFox[iNextPos] = lTotalDist;
				pq.push({ lTotalDist, iNextPos });
			}
		}
	}
}

void dijkstraWolf(int start)
{
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
	pq.push({ 0, start });

	distWolf[start][0] = 0;

	while (!pq.empty())
	{
		int iPos = pq.top().second % 10000;
		int iBoost = pq.top().second / 10000;
		long long lDist = pq.top().first;
		pq.pop();

		if (distWolf[iPos][iBoost] < lDist) continue;
		for (pair<int, int> Node : vecNode[iPos])
		{
			int iNextPos = Node.first;
			long long lTotalDist = lDist + (iBoost == 0 ? Node.second / 2 : Node.second * 2);
			if (lTotalDist < distWolf[iNextPos][(iBoost + 1) % 2])
			{
				distWolf[iNextPos][(iBoost + 1) % 2] = lTotalDist;
				pq.push({ lTotalDist, iNextPos + (iBoost == 0 ? 10000 : 0) });
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

	for (int i = 1; i <= iN; ++i)
	{
		distFox[i] = 1e18;
		distWolf[i][0] = 1e18;
		distWolf[i][1] = 1e18;
	}

	for (int i = 0; i < iM; ++i)
	{
		int iS, iE;
		cin >> iS >> iE;

		long long lW;
		cin >> lW;

		vecNode[iS].push_back({ iE, lW * 2 });
		vecNode[iE].push_back({ iS, lW * 2 });
	}

	dijkstraFox(1);
	dijkstraWolf(1);

	int iAns = 0;
	for (int i = 1; i <= iN; ++i)
	{
		if (distFox[i] < min(distWolf[i][0], distWolf[i][1]))
		{
			++iAns;
		}
	}
	cout << iAns << "\n";
	return 0;
}
