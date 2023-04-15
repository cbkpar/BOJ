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

	vector<vector<bool>> matLight(iN, vector<bool>(iN, false));
	vector<vector<bool>> matMove(iN, vector<bool>(iN, false));
	vector<vector<bool>> matVisited(iN, vector<bool>(iN, false));
	vector<vector<vector<pair<int, int>>>> matSwitch(iN, vector<vector<pair<int, int>>>(iN));

	matLight[0][0] = true;
	matMove[0][0] = true;
	matVisited[0][0] = true;


	while (iM--)
	{
		int iS1, iE1, iS2, iE2;
		cin >> iS1 >> iE1 >> iS2 >> iE2;

		matSwitch[iS1 - 1][iE1 - 1].push_back({ iS2 - 1,iE2 - 1 });

	}

	queue<pair<int, int>> qPos;
	qPos.push({ 0,0 });
	while (!qPos.empty())
	{
		pair<int, int> pPos = qPos.front();
		qPos.pop();
		for (int i = 0; i < 4; ++i)
		{
			int iNextR = pPos.first + dR[i];
			int iNextC = pPos.second + dC[i];
			if (iNextR < 0 || iNextR > iN - 1 || iNextC < 0 || iNextC > iN - 1) continue;
			if (matMove[iNextR][iNextC]) continue;
			matMove[iNextR][iNextC] = true;
			if (matLight[iNextR][iNextC])
			{
				qPos.push({ iNextR, iNextC });
			}
		}
		for (pair<int, int> tPos : matSwitch[pPos.first][pPos.second])
		{
			if (!matLight[tPos.first][tPos.second])
			{
				matLight[tPos.first][tPos.second] = true;
				if (matMove[tPos.first][tPos.second])
				{
					qPos.push({ tPos.first, tPos.second });
				}
			}
		}
	}
	int iAns = 0;
	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iN; ++j)
		{
			if (matLight[i][j])
			{
				++iAns;
			}
		}
	}
	cout << iAns << "\n";
	return 0;
}
