#include <iostream>
#include <string>
#include <queue>

using namespace std;

int matMap[1001][1001] = { 0, };
bool matVisited[1001][1001] = { false, };

int dR[4] = { -1,0,1,0 };
int dC[4] = { 0,-1,0,1 };

void Solve()
{
	queue<pair<int, int>> queuePlayer;
	queue<pair<int, int>> queueFire;

	int iR, iC;
	cin >> iC >> iR;

	for (int i = 0; i < iR; ++i)
	{
		string strMap;
		cin >> strMap;
		for (int j = 0; j < iC; ++j)
		{
			if (strMap[j] == '#')
			{
				matVisited[i][j] = true;
			}
			else if (strMap[j] == '@')
			{
				queuePlayer.emplace(make_pair(i, j));
				matVisited[i][j] = true;
			}
			else if (strMap[j] == '*')
			{
				queueFire.emplace(make_pair(i, j));
				matVisited[i][j] = true;
			}
			else
			{
				matVisited[i][j] = false;
			}
		}
	}
	int iCount = 0;
	while (!queuePlayer.empty())
	{
		++iCount;
		int iSize = queueFire.size();
		for (int i = 0; i < iSize; ++i)
		{
			int iNowR = queueFire.front().first;
			int iNowC = queueFire.front().second;
			queueFire.pop();
			for (int j = 0; j < 4; ++j)
			{
				int iNextR = iNowR + dR[j];
				int iNextC = iNowC + dC[j];
				if (iNextR < 0 || iNextR > iR - 1 || iNextC <0 || iNextC > iC - 1)
				{
					continue;
				}
				if (matVisited[iNextR][iNextC])
				{
					continue;
				}
				matVisited[iNextR][iNextC] = true;
				queueFire.emplace(make_pair(iNextR, iNextC));
			}
		}
		iSize = queuePlayer.size();
		for (int i = 0; i < iSize; ++i)
		{
			int iNowR = queuePlayer.front().first;
			int iNowC = queuePlayer.front().second;
			queuePlayer.pop();
			for (int j = 0; j < 4; ++j)
			{
				int iNextR = iNowR + dR[j];
				int iNextC = iNowC + dC[j];
				if (iNextR < 0 || iNextR > iR - 1 || iNextC <0 || iNextC > iC - 1)
				{
					cout << iCount << "\n";
					return;
				}
				if (matVisited[iNextR][iNextC])
				{
					continue;
				}
				matVisited[iNextR][iNextC] = true;
				queuePlayer.emplace(make_pair(iNextR, iNextC));
			}
		}
	}
	cout << "IMPOSSIBLE\n";
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
		Solve();
	}
	return 0;
}
