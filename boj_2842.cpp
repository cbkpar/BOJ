#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int dR[8] = { -1,-1,-1,0,0,1,1,1 };
int dC[8] = { -1,0,1,-1,1,-1,0,1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	vector<bool> vecHeight(1000001, false);
	vector<vector<int>> matWorld(iN, vector<int>(iN, 0));
	vector<vector<int>> matHeight(iN, vector<int>(iN, 0));

	pair<int, int> pStart;
	int iParcleCount = 0;

	for (int i = 0; i < iN; ++i)
	{
		string strMap;
		cin >> strMap;
		for (int j = 0; j < iN; ++j)
		{
			if (strMap[j] == 'P')
			{
				pStart.first = i;
				pStart.second = j;
				matWorld[i][j] = 1;
			}
			else if (strMap[j] == 'K')
			{
				matWorld[i][j] = 2;
				++iParcleCount;
			}
		}
	}
	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iN; ++j)
		{
			cin >> matHeight[i][j];
			vecHeight[matHeight[i][j]] = true;
		}
	}

	vector<int> vecH;
	for (int i = 1; i <= 1000000; ++i)
	{
		if (vecHeight[i])
		{
			vecH.push_back(i);
		}
	}

	int iAns = 2000000000;

	int iSize = vecH.size();
	int iLeft = 0;
	int iRight = 0;
	while (iLeft <= iRight && iRight < iSize)
	{
		vector<vector<bool>> matVisited(iN, vector<bool>(iN, false));
		int iCount = 0;
		queue<pair<int, int>> qPos;

		if (matHeight[pStart.first][pStart.second] >= vecH[iLeft] &&
			matHeight[pStart.first][pStart.second] <= vecH[iRight])
		{
			qPos.push(pStart);
			matVisited[pStart.first][pStart.second] = true;
		}

		while (!qPos.empty())
		{
			pair<int, int> pPos = qPos.front();
			qPos.pop();

			for (int i = 0; i < 8; ++i)
			{
				int iNextR = pPos.first + dR[i];
				int iNextC = pPos.second + dC[i];

				if (iNextR < 0 || iNextR > iN - 1 || iNextC < 0 || iNextC > iN - 1) continue;
				if (matVisited[iNextR][iNextC]) continue;

				matVisited[iNextR][iNextC] = true;
				if (matHeight[iNextR][iNextC] >= vecH[iLeft] &&
					matHeight[iNextR][iNextC] <= vecH[iRight])
				{
					if (matWorld[iNextR][iNextC] == 2) ++iCount;
					qPos.push({ iNextR, iNextC });
				}
			}
		}

		if (iCount == iParcleCount)
		{
			iAns = min(iAns, vecH[iRight] - vecH[iLeft]);
			++iLeft;
		}
		else
		{
			++iRight;
		}
	}
	cout << iAns << "\n";
	return 0;
}
