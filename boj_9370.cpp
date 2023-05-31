#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void dijkstra(const vector<vector<pair<int, int>>>& vecNode, vector<int>& vecDist, int start)
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
		for (pair<int, int> Node : vecNode[iPos])
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

	int iT;
	cin >> iT;
	while (iT--)
	{
		int iN, iM, iC;
		cin >> iN >> iM >> iC;

		int iS, iG, iH;
		cin >> iS >> iG >> iH;

		vector<vector<pair<int, int>>> vecNode(iN + 1, vector<pair<int, int>>());
		vector<int> vecDistG(iN + 1, 500000000);
		vector<int> vecDistH(iN + 1, 500000000);
		vector<int> vecDistS(iN + 1, 500000000);

		while (iM--)
		{
			int iStart, iEnd, iDist;
			cin >> iStart >> iEnd >> iDist;
			vecNode[iStart].push_back({ iEnd,iDist });
			vecNode[iEnd].push_back({ iStart,iDist });
		}
		dijkstra(vecNode, vecDistS, iS);
		dijkstra(vecNode, vecDistG, iG);
		dijkstra(vecNode, vecDistH, iH);

		vector<int> vecAns;
		while (iC--)
		{
			int iNum;
			cin >> iNum;
			int iDist = min(vecDistG[iS] + vecDistH[iNum], vecDistG[iNum] + vecDistH[iS]);
			iDist += vecDistG[iH];
			if (iDist <= vecDistS[iNum])
			{
				vecAns.push_back(iNum);
			}
		}

		sort(vecAns.begin(), vecAns.end());
		int iSize = vecAns.size();
		for (int i = 0; i < iSize; ++i)
		{
			cout << vecAns[i] << (i == iSize - 1 ? "\n" : " ");
		}
	}

	return 0;
}
