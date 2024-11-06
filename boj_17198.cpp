#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int dR[4] = { -1,0,1,0 };
int dC[4] = { 0,-1,0,1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<string> vecMap(10, "");
	for (int i = 0;i < 10;++i)
	{
		cin >> vecMap[i];
	}

	pair<int, int> pGoal = { 0,0 };
	pair<int, int> pStone = { 0,0 };

	vector<vector<bool>> matVisited(10, vector<bool>(10, false));
	queue<pair<int, int>> qPos;
	for (int i = 0;i < 10;++i)
	{
		for (int j = 0;j < 10;++j)
		{
			if (vecMap[i][j] == 'L')
			{
				qPos.push({ i,j });
				matVisited[i][j] = true;
			}
			if (vecMap[i][j] == 'R') pStone = { i,j };
			if (vecMap[i][j] == 'B') pGoal = { i,j };
		}
	}

	int iCount = 0;
	while (!qPos.empty())
	{
		int iSize = qPos.size();
		for (int i = 0;i < iSize;++i)
		{
			pair<int, int> pNow = qPos.front();
			qPos.pop();

			for (int k = 0;k < 4;++k)
			{
				pair<int, int> pNext = { pNow.first + dR[k], pNow.second + dC[k] };
				if (pNext.first < 0 || pNext.first > 9 || pNext.second < 0 || pNext.second > 9) continue;
				if (pNext.first == pStone.first && pNext.second == pStone.second) continue;
				if (pNext.first == pGoal.first && pNext.second == pGoal.second)
				{
					cout << iCount << "\n";
					return 0;
				}
				if (!matVisited[pNext.first][pNext.second])
				{
					matVisited[pNext.first][pNext.second] = true;
					qPos.push(pNext);
				}

			}
		}
		++iCount;
	}
	return 0;
}
