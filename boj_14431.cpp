#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;

int CalcDist(const pair<int, int>& o1, const pair<int, int>& o2)
{
	int iDiffX = o1.first - o2.first;
	int iDiffY = o1.second - o2.second;
	int iDist = (int)sqrt(iDiffX * iDiffX + iDiffY * iDiffY);
	return iDist;
}

void dijkstra(const vector<vector<pair<int,int>>>& vecNode, vector<int>& vecDist, const int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, start });

	vecDist[start] = 0;

	while (!pq.empty())
	{
		int iPos = pq.top().second;
		int iDist = pq.top().first;
		pq.pop();

		if (vecDist[iPos] < iDist) continue;
		for (const pair<int,int>& Node : vecNode[iPos])
		{
			int iNextPos = Node.first;
			int iTotalDist = iDist + Node.second;
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

	bool ArrPrime[100001] = { false, };
	ArrPrime[0] = ArrPrime[1] = true;
	for (int i = 2; i * i <= 100000; i++) {
		for (int j = i * i; j <= 100000; j += i) {
			ArrPrime[j] = true;
		}
	}

	pair<int, int> pPosA, pPosB;
	cin >> pPosA.first >> pPosA.second;
	cin >> pPosB.first >> pPosB.second;

	int iN;
	cin >> iN;

	vector<pair<int, int>> vecNode(iN + 2, { 0,0 });
	vector<int> vecDist(iN + 2, 1000000000);
	vecNode[0].first = pPosA.first;
	vecNode[0].second = pPosA.second;
	vecNode[iN+1].first = pPosB.first;
	vecNode[iN+1].second = pPosB.second;
	for (int i = 1; i <= iN; ++i)
	{
		cin >> vecNode[i].first >> vecNode[i].second;
	}

	vector<vector<pair<int,int>>> vecNext(iN + 2, vector<pair<int,int>>());
	for (int i = 0; i <= iN + 1; ++i)
	{
		for (int j = i + 1; j <= iN + 1; ++j)
		{
			int iDist = CalcDist(vecNode[i], vecNode[j]);
			if (!ArrPrime[iDist])
			{
				vecNext[i].push_back({ j,iDist });
				vecNext[j].push_back({ i,iDist });
			}
		}
	}

	dijkstra(vecNext, vecDist, 0);
	if (vecDist[iN + 1] == 1000000000)
	{
		cout << "-1\n";
	}
	else
	{
		cout << vecDist[iN+1] << "\n";
	}
	return 0;
}
