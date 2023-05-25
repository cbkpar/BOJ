#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int dR[4] = { -1,0,1,0 };
int dC[4] = { 0,-1,0,1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	vector<vector<bool>> matVisited(iN, vector<bool>(iN, false));
	vector<string> matMap(iN, "");
	for (int i = 0; i < iN; ++i) cin >> matMap[i];

	int iAns = 0;
	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iN; ++j)
		{
			if (matMap[i][j] == '*' && !matVisited[i][j])
			{
				queue<pair<int, int>> qPos;
				qPos.push({ i,j });
				matVisited[i][j] = true;
				++iAns;

				while (!qPos.empty())
				{
					pair<int, int> NowPos = qPos.front();
					qPos.pop();
					for (int k = 0; k < 4; ++k)
					{
						int iNextR = NowPos.first + dR[k];
						int iNextC = NowPos.second + dC[k];
						if (iNextR<0 || iNextR>iN - 1 || iNextC<0 || iNextC>iN - 1) continue;
						if (matMap[iNextR][iNextC] == '*' && !matVisited[iNextR][iNextC])
						{
							matVisited[iNextR][iNextC] = true;
							qPos.push({ iNextR, iNextC });
						}
					}
				}
			}
		}
	}
	cout << iAns << "\n";
	return 0;
}
