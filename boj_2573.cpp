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

	vector<vector<int>> matMap(iN, vector<int>(iM, 0));
	for (int i = 0;i < iN;++i)
	{
		for (int j = 0;j < iM;++j)
		{
			cin >> matMap[i][j];
		}
	}
	
	int iAns = 0;

	int iTime = 0;
	while (true)
	{
		int iCount = 0;
		vector<vector<bool>> vecVisited(iN, vector<bool>(iM, false));
		for (int i = 0;i < iN;++i)
		{
			for (int j = 0;j < iM;++j)
			{
				if (vecVisited[i][j]) continue;
				if (matMap[i][j] > 0)
				{
					++iCount;
					queue<pair<int, int>> qTemp;
					qTemp.push({ i,j });
					vecVisited[i][j] = true;
					while (!qTemp.empty())
					{
						pair<int, int> pTemp = qTemp.front();
						qTemp.pop();
						for (int k = 0;k < 4;++k)
						{
							int iNextR = pTemp.first + dR[k];
							int iNextC = pTemp.second + dC[k];
							if (iNextR < 0 || iNextR > iN - 1 || iNextC < 0 || iNextC > iM - 1) continue;
							if (vecVisited[iNextR][iNextC] || matMap[iNextR][iNextC] <= 0) continue;

							vecVisited[iNextR][iNextC] = true;
							qTemp.push({ iNextR, iNextC });
						}
					}
				}
			}
		}
		if (iCount == 0) break;
		if (iCount >= 2)
		{
			iAns = iTime;
			break;
		}
		++iTime;

		vector<vector<int>> matCount(iN, vector<int>(iM, 0));
		for (int i = 0;i < iN;++i)
		{
			for (int j = 0;j < iM;++j)
			{
				for (int k = 0;k < 4;++k)
				{
					int iNextR = i + dR[k];
					int iNextC = j + dC[k];
					if (iNextR < 0 || iNextR > iN - 1 || iNextC < 0 || iNextC > iM - 1) continue;
					if (matMap[iNextR][iNextC] == 0)
					{
						++matCount[i][j];
					}
				}
			}
		}
		for (int i = 0;i < iN;++i)
		{
			for (int j = 0;j < iM;++j)
			{
				matMap[i][j] -= matCount[i][j];
				if (matMap[i][j] < 0) matMap[i][j] = 0;
			}
		}

	}

	cout << iAns << "\n";
	return 0;
}
