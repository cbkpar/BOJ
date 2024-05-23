#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<pair<int, long long>>> vecNode(50, vector<pair<int, long long>>());
vector<vector<int>> vecReverse(50, vector<int>());
long long dist[50] = { 0, };
vector<long long> vecSalary(50, 0);
vector<bool> vecLink(50, 0);
int iN;

void bellman(int start, int end)
{
	dist[start] = vecSalary[start];

	for (int i = 0;i < iN - 1;++i)
	{
		for (int j = 0;j < iN;++j)
		{
			if (dist[j] == -1000000000000000L) continue;
			int iSize = vecNode[j].size();
			for (int k = 0;k < iSize;++k)
			{
				long long iTotalDist = dist[j] + vecNode[j][k].second;
				if (iTotalDist > dist[vecNode[j][k].first])
				{
					dist[vecNode[j][k].first] = iTotalDist;
				}
			}
		}
	}

	for (int j = 0;j < iN;++j)
	{
		if (dist[j] == -1000000000000000L) continue;
		int iSize = vecNode[j].size();
		for (int k = 0;k < iSize;++k)
		{
			long long iTotalDist = dist[j] + vecNode[j][k].second;
			if (iTotalDist > dist[vecNode[j][k].first])
			{
				if (vecLink[vecNode[j][k].first])
				{
					cout << "Gee" << "\n";
					return;
				}
			}
		}
	}

	long long lTemp2 = dist[end];

	if (dist[end] == -1000000000000000L)
	{
		cout << "gg" << "\n";
	}
	else
	{
		cout << dist[end] << "\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iStart, iEnd, iM;
	cin >> iN >> iStart >> iEnd >> iM;

	for (int i = 0;i < iN;++i)
	{
		dist[i] = -1000000000000000L;
	}
	while (iM--)
	{
		int iS, iE;
		long long lCost;
		cin >> iS >> iE >> lCost;

		vecNode[iS].push_back({ iE, -lCost });
		vecReverse[iE].push_back(iS);
	}

	for (int i = 0;i < iN;++i)
	{
		cin >> vecSalary[i];
	}

	for (int i = 0;i < iN;++i)
	{
		int iSize = vecNode[i].size();
		for (int j = 0;j < iSize;++j)
		{
			vecNode[i][j].second += vecSalary[vecNode[i][j].first];
		}
	}

	vector<bool> vecVisited(iN, false);
	queue<int> qPos;
	vecVisited[iEnd] = true;
	qPos.push(iEnd);
	vecLink[iEnd] = true;
	while (!qPos.empty())
	{
		int iPos = qPos.front();
		qPos.pop();

		for (int iNextPos : vecReverse[iPos])
		{
			if (!vecVisited[iNextPos])
			{
				vecVisited[iNextPos] = true;
				qPos.push(iNextPos);
				vecLink[iNextPos] = true;
			}
		}
	}

	bellman(iStart, iEnd);
	return 0;
}
