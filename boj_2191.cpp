#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

bool Bipartite(const vector<vector<int>>& Node, vector<bool>& Visited, vector<int>& Next, int now)
{
	for (int next : Node[now])
	{
		if (Visited[next]) continue;
		Visited[next] = true;

		if (Next[next] == 0 || Bipartite(Node, Visited, Next, Next[next]))
		{
			Next[next] = now;
			return true;
		}
	}
	return false;
}

double CalcDist(const pair<double, double>& Pos1, const pair<double, double>& Pos2)
{
	double dX = Pos1.first - Pos2.first;
	double dY = Pos1.second - Pos2.second;
	return sqrt(dX * dX + dY * dY);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM, iS, iV;
	cin >> iN >> iM >> iS >> iV;

	vector<pair<double, double>> vecMouse(iN + 1, { 0,0 });
	vector<pair<double, double>> vecTunnel(iM + 1, { 0,0 });
	for (int i = 1; i <= iN; ++i) cin >> vecMouse[i].first >> vecMouse[i].second;
	for (int i = 1; i <= iM; ++i) cin >> vecTunnel[i].first >> vecTunnel[i].second;

	vector<vector<int>> vecNode(iN + 1, vector<int>());
	for (int i = 1; i <= iN; ++i)
	{
		for (int j = 1; j <= iM; ++j)
		{
			if (CalcDist(vecMouse[i], vecTunnel[j]) <= (double)iS * iV)
			{
				vecNode[i].push_back(j);
			}
		}
	}
	vector<int> vecNext(iM + 1, 0);
	for (int i = 1; i <= iN; ++i)
	{
		vector<bool> vecVisited(iM + 1, false);
		Bipartite(vecNode, vecVisited, vecNext, i);
	}

	int iAns = 0;
	for (int i = 1; i <= iM; ++i)
	{
		if (vecNext[i] > 0)
		{
			++iAns;
		}
	}
	cout << (iN - iAns) << "\n";
	return 0;
}
