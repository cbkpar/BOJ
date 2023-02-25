#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int dR[4] = { -1,0,1,0 };
int dC[4] = { 0,-1,0,1 };

int BitCount(uint32_t i)
{
	i = i - ((i >> 1) & 0x55555555);
	i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
	i = (i + (i >> 4)) & 0x0F0F0F0F;
	return (i * 0x01010101) >> 24;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;
	int iZero = 0;
	int iVirus = 0;

	vector<vector<int>> matMap(iN, vector<int>(iN, 0));
	vector<pair<int, int>> vecVirus;
	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iN; ++j)
		{
			cin >> matMap[i][j];
			if (matMap[i][j] == 2)
			{
				++iVirus;
				vecVirus.push_back({ i,j });
			}
			if (matMap[i][j] == 0)
			{
				++iZero;
			}
		}
	}
	int iBitMax = 1 << iVirus;
	int iAns = 1000000000;

	vector<vector<int>> matTempMap(iN, vector<int>(iN, 0));
	for (int t = 0; t < iBitMax; ++t)
	{
		if (BitCount(t) != iM) continue;
		for (int i = 0; i < iN; ++i)
		{
			for (int j = 0; j < iN; ++j)
			{
				matTempMap[i][j] = matMap[i][j];
			}
		}

		queue<pair<int, int>> qVirus;
		int iMoveCount = 0;
		int iZeroCount = iZero;

		int iTemp = t;
		int iVirusCount = 0;
		for (int i = 0; i < iVirus; ++i)
		{
			if (iTemp & 1)
			{
				matTempMap[vecVirus[i].first][vecVirus[i].second] = 3;
				qVirus.push(vecVirus[i]);
				++iVirusCount;
			}
			iTemp /= 2;
		}

		while (!qVirus.empty())
		{
			if (iZeroCount == 0) break;
			int iCount = qVirus.size();
			while (iCount--)
			{
				pair<int, int> pos = qVirus.front();
				qVirus.pop();
				for (int i = 0; i < 4; ++i)
				{
					int iNowR = pos.first + dR[i];
					int iNowC = pos.second + dC[i];

					if (iNowR<0 || iNowR>iN - 1 || iNowC<0 || iNowC>iN - 1) continue;
					if (matTempMap[iNowR][iNowC] == 0)
					{
						--iZeroCount;
						matTempMap[iNowR][iNowC] = 3;
						qVirus.push({ iNowR,iNowC });
					}
					else if (matTempMap[iNowR][iNowC] == 2)
					{
						matTempMap[iNowR][iNowC] = 3;
						qVirus.push({ iNowR,iNowC });
					}
				}
			}
			++iMoveCount;
		}
		if (iZeroCount == 0)
		{
			iAns = min(iAns, iMoveCount);
		}
	}

	if (iAns == 1000000000)
	{
		cout << "-1";
	}
	else
	{
		cout << iAns << "\n";
	}

	return 0;
}
