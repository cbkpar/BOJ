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

	int iR, iC;
	cin >> iR >> iC;

	vector<string> matMap(iR, "");
	for (int i = 0; i < iR; ++i) cin >> matMap[i];

	int iCount = 0;
	vector<vector<bool>> matVisited(iR, vector<bool>(iC, false));
	for (int i = 0; i < iR; ++i)
	{
		for (int j = 0; j < iC; ++j)
		{
			if (!matVisited[i][j] && matMap[i][j] == '.')
			{
				++iCount;
				queue<pair<int, int>> qPos;
				qPos.push({ i,j });
				matVisited[i][j] = true;

				while (!qPos.empty())
				{
					pair<int, int> pNow = qPos.front();
					qPos.pop();
					for (int k = 0; k < 4; ++k)
					{
						pair<int, int> pNext = { pNow.first + dR[k],pNow.second + dC[k] };
						if (pNext.first < 0 || pNext.first > iR - 1 || pNext.second < 0 || pNext.second > iC - 1) continue;
						if (matVisited[pNext.first][pNext.second]) continue;
						qPos.push(pNext);
						matVisited[pNext.first][pNext.second] = true;
					}
				}
			}
		}
	}
	if (iCount > 1)
	{
		cout << "1\n";
		return 0;
	}
	for (int i = 0; i < iR; ++i)
	{
		for (int j = 0; j < iC; ++j)
		{
			if (matMap[i][j] == '.')
			{
				int iPathCount = 0;
				for (int k = 0; k < 4; ++k)
				{
					pair<int, int> pNext = { i + dR[k],j + dC[k] };
					if (pNext.first < 0 || pNext.first > iR - 1 || pNext.second < 0 || pNext.second > iC - 1) continue;
					if (matMap[pNext.first][pNext.second] == '.') ++iPathCount;
				}
				if (iPathCount < 2)
				{
					cout << "1\n";
					return 0;
				}
			}
		}
	}
	cout << "0\n";
	return 0;
}
