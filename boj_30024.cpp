#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int dR[4] = { -1,0,1,0 };
int dC[4] = { 0,-1,0,1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;

	vector<vector<long long>> matAmount(iN, vector<long long>(iM, 0));
	vector<vector<bool>> matVisited(iN, vector<bool>(iM, false));
	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iM; ++j)
		{
			cin >> matAmount[i][j];
		}
	}

	int iK;
	cin >> iK;
	priority_queue<pair<long long, pair<int, int>>, vector<pair<long long, pair<int, int>>>, less<>> pq;

	for (int i = 0; i < iM; ++i)
	{
		if (!matVisited[0][i])
		{
			matVisited[0][i] = true;
			pq.push({ matAmount[0][i],{0,i} });
		}
		if (!matVisited[iN - 1][i])
		{
			matVisited[iN - 1][i] = true;
			pq.push({ matAmount[iN - 1][i],{iN - 1,i} });
		}
	}

	for (int i = 0; i < iN; ++i)
	{
		if (!matVisited[i][0])
		{
			matVisited[i][0] = true;
			pq.push({ matAmount[i][0],{i,0} });
		}
		if (!matVisited[i][iM - 1])
		{
			matVisited[i][iM - 1] = true;
			pq.push({ matAmount[i][iM - 1],{i,iM - 1} });
		}
	}

	while (iK--)
	{
		pair<long long, pair<int, int>> pNow = pq.top();
		pq.pop();
		cout << (pNow.second.first + 1) << " " << (pNow.second.second + 1) << "\n";

		for (int i = 0; i < 4; ++i)
		{
			int iNextR = pNow.second.first + dR[i];
			int iNextC = pNow.second.second + dC[i];
			if (iNextR < 0 || iNextR > iN - 1 || iNextC < 0 || iNextC > iM - 1) continue;
			if (matVisited[iNextR][iNextC]) continue;
			matVisited[iNextR][iNextC] = true;
			pq.push({ matAmount[iNextR][iNextC],{iNextR, iNextC} });
		}
	}

	return 0;
}
