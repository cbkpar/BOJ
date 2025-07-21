#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void dijkstra(const vector<vector<pair<int, int>>>& vecNode, vector<int>& vecDist, int start, int iLimit)
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
			int iTotalDist = iDist + (Node.second > iLimit ? 1 : 0);
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

	int iN, iP, iK;
	cin >> iN >> iP >> iK;

	int iLeft = 0;
	int iRight = 1000000;
	int iAns = 1000000000;

	vector<vector<pair<int, int>>> vecNode(iN + 1, vector<pair<int, int>>());
	for (int i = 0;i < iP;++i)
	{
		int iS, iE, iW;
		cin >> iS >> iE >> iW;
		vecNode[iS].push_back({ iE,iW });
		vecNode[iE].push_back({ iS,iW });
	}

	while (iLeft <= iRight)
	{
		int iMid = (iLeft + iRight) >> 1;
		vector<int> vecDist(iN + 1, 500000000);
		dijkstra(vecNode, vecDist, 1, iMid);
		if (vecDist[iN] > iK)
		{
			iLeft = iMid + 1;
		}
		else
		{
			iAns = min(iAns, iMid);
			iRight = iMid - 1;
		}
	}

	if (iAns == 1000000000)
	{
		cout << "-1" << "\n";
	}
	else
	{
		cout << iAns << "\n";
	}

	return 0;
}
