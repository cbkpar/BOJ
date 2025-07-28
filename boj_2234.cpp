#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int dR[4] = { 0,-1,0,1 };
int dC[4] = { -1,0,1,0 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iM >> iN;

	vector<vector<int>> matMap(iN, vector<int>(iM, 0));
	for (int i = 0;i < iN;++i)
	{
		for (int j = 0;j < iM;++j)
		{
			cin >> matMap[i][j];
		}
	}

	vector<vector<int>> matMapGroup(iN, vector<int>(iM, 0));
	vector<int> vecCount(iN * iM + 1, 0);
	int iNowGroup = 0;
	for (int i = 0;i < iN;++i)
	{
		for (int j = 0;j < iM;++j)
		{
			if (matMapGroup[i][j] == 0)
			{
				matMapGroup[i][j] = ++iNowGroup;
				++vecCount[iNowGroup];
				queue<pair<int, int>> qPos;
				qPos.push({ i,j });

				while (!qPos.empty())
				{
					pair<int, int> pPos = qPos.front();
					qPos.pop();

					int iR = pPos.first;
					int iC = pPos.second;

					for (int k = 0;k < 4;++k)
					{
						int iNextR = iR + dR[k];
						int iNextC = iC + dC[k];
						if (iNextR < 0 || iNextR > iN - 1 || iNextC < 0 || iNextC > iM - 1) continue;
						if (matMapGroup[iNextR][iNextC] != 0) continue;
						if ((matMap[iR][iC] & (1 << k)) == (1 << k)) continue;

						matMapGroup[iNextR][iNextC] = matMapGroup[i][j];
						++vecCount[iNowGroup];

						qPos.push({ iNextR, iNextC });
					}
				}
			}
		}
	}

	cout << iNowGroup << "\n";

	int iMaxSingle = 0;
	for (int i = 1;i <= iNowGroup;++i)
	{
		iMaxSingle = max(iMaxSingle, vecCount[i]);
	}
	cout << iMaxSingle << "\n";

	int iMaxDouble = 0;
	for (int i = 0;i < iN;++i)
	{
		for (int j = 0;j < iM;++j)
		{
			for (int k = 0;k < 4;++k)
			{
				int iNextR = i + dR[k];
				int iNextC = j + dC[k];
				if (iNextR < 0 || iNextR > iN - 1 || iNextC < 0 || iNextC > iM - 1) continue;
				if (matMapGroup[i][j] != matMapGroup[iNextR][iNextC])
				{
					iMaxDouble = max(iMaxDouble, vecCount[matMapGroup[i][j]] + vecCount[matMapGroup[iNextR][iNextC]]);
				}
			}
		}
	}
	cout << iMaxDouble << "\n";
	return 0;
}
