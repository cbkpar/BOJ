#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int dR[4] = { -1,0,1,0 };
int dC[4] = { 0,-1,0,1 };

bool IsConnected(const vector<vector<int>>& matSelect)
{
	int iCount = 0;
	for (int i = 0;i < 25;++i)
	{
		int iR = i / 5;
		int iC = i % 5;
		if (matSelect[iR][iC] > 0)
		{
			vector<vector<bool>> matVisited(5, vector<bool>(5, false));
			iCount = 1;
			matVisited[iR][iC] = true;
			queue<pair<int, int>> qPos;
			qPos.push({ iR,iC });
			while (!qPos.empty())
			{
				pair<int, int> pPos = qPos.front();
				qPos.pop();
				for (int t = 0;t < 4;++t)
				{
					int iNextR = pPos.first + dR[t];
					int iNextC = pPos.second + dC[t];
					if (iNextR < 0 || iNextR > 4 || iNextC < 0 || iNextC > 4) continue;
					if (matSelect[iNextR][iNextC] == 0 || matVisited[iNextR][iNextC]) continue;
					matVisited[iNextR][iNextC] = true;
					++iCount;
					qPos.push({ iNextR, iNextC });
				}
			}
			break;
		}
	}
	return (iCount == 7 ? true : false);
}

int FindPrincess(vector<vector<int>>& matSelect, int iS, int iCount, int iNow, const vector<vector<int>>& matMap)
{
	int iRet = 0;
	if (iCount == 7)
	{
		if (iS < 4) return 0;
		return (IsConnected(matSelect) ? 1 : 0);
	}
	if (iNow < 25)
	{
		int iR = iNow / 5;
		int iC = iNow % 5;
		if (matMap[iR][iC] == 1)
		{
			matSelect[iR][iC] = 1;
			iRet += FindPrincess(matSelect, iS + 1, iCount + 1, iNow + 1, matMap);
			matSelect[iR][iC] = 0;
		}
		else
		{
			matSelect[iR][iC] = 2;
			iRet += FindPrincess(matSelect, iS, iCount + 1, iNow + 1, matMap);
			matSelect[iR][iC] = 0;
		}
		iRet += FindPrincess(matSelect, iS, iCount, iNow + 1, matMap);
	}

	return iRet;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	vector<vector<int>> matMap(5, vector<int>(5, 0));
	vector<vector<int>> matSelect(5, vector<int>(5, 0));
	for (int i = 0;i < 5;++i)
	{
		string strTeam;
		cin >> strTeam;

		for (int j = 0;j < 5;++j)
		{
			if (strTeam[j] == 'S')
			{
				matMap[i][j] = 1;
			}
		}
	}

	int iAns = FindPrincess(matSelect, 0, 0, 0, matMap);
	cout << iAns << "\n";
	return 0;
}
