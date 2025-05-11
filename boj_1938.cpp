#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>

using namespace std;

int matCount[50][50][2] = { 0, };

int dR[4] = { -1,0,1,0 };
int dC[4] = { 0,-1,0,1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	tuple<int, int, int> tStart;
	tuple<int, int, int> tEnd;

	vector<string> vecMap(iN, "");
	for (int i = 0; i < iN; ++i)
	{
		cin >> vecMap[i];
	}

	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iN; ++j)
		{
			for (int k = 0; k < 2; ++k)
			{
				matCount[i][j][k] = -1;
			}
		}
	}


	for (int i = 1; i < iN - 1; ++i)
	{
		for (int j = 0; j < iN; ++j)
		{
			if (vecMap[i][j] == 'B' && vecMap[i - 1][j] == 'B' && vecMap[i + 1][j] == 'B')
			{
				tStart = make_tuple(i, j, 0);
				matCount[i][j][0] = 0;
			}
			if (vecMap[i][j] == 'E' && vecMap[i - 1][j] == 'E' && vecMap[i + 1][j] == 'E')
			{
				tEnd = make_tuple(i, j, 0);
			}
		}
	}
	for (int i = 0; i < iN; ++i)
	{
		for (int j = 1; j < iN - 1; ++j)
		{
			if (vecMap[i][j] == 'B' && vecMap[i][j - 1] == 'B' && vecMap[i][j + 1] == 'B')
			{
				tStart = make_tuple(i, j, 1);
				matCount[i][j][1] = 0;
			}
			if (vecMap[i][j] == 'E' && vecMap[i][j - 1] == 'E' && vecMap[i][j + 1] == 'E')
			{
				tEnd = make_tuple(i, j, 1);
			}
		}
	}

	int iNow = 0;
	queue<tuple<int, int, int>> qPos;
	qPos.push(tStart);
	while (!qPos.empty())
	{
		++iNow;
		int iSize = qPos.size();
		while (iSize-- > 0)
		{
			int iR = get<0>(qPos.front());
			int iC = get<1>(qPos.front());
			int iT = get<2>(qPos.front());
			qPos.pop();

			if (iT == 0)
			{
				for (int i = 0; i < 4; ++i)
				{
					int iNextR = iR + dR[i];
					int iNextC = iC + dC[i];
					if (iNextR < 1 || iNextR > iN - 2 || iNextC < 0 || iNextC > iN - 1) continue;
					if (matCount[iNextR][iNextC][0] != -1) continue;
					if (vecMap[iNextR][iNextC] == '1' || vecMap[iNextR - 1][iNextC] == '1' || vecMap[iNextR + 1][iNextC] == '1') continue;
					matCount[iNextR][iNextC][0] = iNow;
					qPos.push(make_tuple(iNextR, iNextC, 0));
				}
			}
			else if (iT == 1)
			{
				for (int i = 0; i < 4; ++i)
				{
					int iNextR = iR + dR[i];
					int iNextC = iC + dC[i];
					if (iNextR < 0 || iNextR > iN - 1 || iNextC < 1 || iNextC > iN - 2) continue;
					if (matCount[iNextR][iNextC][1] != -1) continue;
					if (vecMap[iNextR][iNextC] == '1' || vecMap[iNextR][iNextC - 1] == '1' || vecMap[iNextR][iNextC + 1] == '1') continue;
					matCount[iNextR][iNextC][1] = iNow;
					qPos.push(make_tuple(iNextR, iNextC, 1));
				}
			}

			bool bPossible = true;
			int iNextT = (iT + 1) % 2;
			if (iR < 1 || iR > iN - 2 || iC < 1 || iC > iN - 2) continue;
			if (matCount[iR][iC][iNextT] != -1) continue;
			for (int i = -1; i <= 1; ++i)
			{
				for (int j = -1; j <= 1; ++j)
				{
					if (vecMap[iR + i][iC + j] == '1')
					{
						bPossible = false;
					}
				}
			}
			if (bPossible)
			{
				matCount[iR][iC][iNextT] = iNow;
				qPos.push(make_tuple(iR, iC, iNextT));
			}
		}
	}

	int iAns = matCount[get<0>(tEnd)][get<1>(tEnd)][get<2>(tEnd)];
	if (iAns == -1) iAns = 0;

	cout << iAns << "\n";
	return 0;
}
