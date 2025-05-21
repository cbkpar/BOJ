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

	vector<string> vecMapA(iN, "");
	for (int i = 0;i < iN;++i)
	{
		cin >> vecMapA[i];
	}

	vector<string> vecMapB(iN, "");
	for (int i = 0;i < iN;++i)
	{
		cin >> vecMapB[i];
	}

	vector<vector<bool>> matVisited(iN, vector<bool>(iM, false));

	bool bPossible = true;
	for (int i = 0;i < iN;++i)
	{
		for (int j = 0;j < iM;++j)
		{
			if (!matVisited[i][j])
			{
				char ch = vecMapB[i][j];
				queue<pair<int, int>> qPos;
				qPos.push({ i,j });
				while (!qPos.empty())
				{
					int iNowR = qPos.front().first;
					int iNowC = qPos.front().second;
					qPos.pop();
					for (int k = 0;k < 4;++k)
					{
						int iNextR = iNowR + dR[k];
						int iNextC = iNowC + dC[k];
						if (iNextR < 0 || iNextR > iN - 1 || iNextC < 0 || iNextC > iM - 1) continue;
						if (matVisited[iNextR][iNextC]) continue;
						if (vecMapA[iNextR][iNextC] != vecMapA[iNowR][iNowC]) continue;
						matVisited[iNextR][iNextC] = true;
						if (vecMapB[iNextR][iNextC] != ch) bPossible = false;
						qPos.push({ iNextR,iNextC });
					}
				}
			}
		}
	}

	if (bPossible)
	{
		cout << "YES" << "\n";
	}
	else
	{
		cout << "NO" << "\n";
	}

	return 0;
}
