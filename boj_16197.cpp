#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int dR[4] = { -1,0,1,0 };
int dC[4] = { 0,-1,0,1 };
int iN, iM;
bool matWorld[20][20] = { false, };
int iAns = 2147483647;

void FindWay(int iK, vector<pair<int, int>> vecPos)
{
	if (iK > 10) return;
	for (int i = 0;i < 4;++i)
	{
		int iExitCount = 0;
		vector<pair<int, int>> vecNext(2, { 0,0 });
		for (int j = 0;j < 2;++j)
		{
			vecNext[j].first = vecPos[j].first;
			vecNext[j].second = vecPos[j].second;
			int iR = vecPos[j].first + dR[i];
			int iC = vecPos[j].second + dC[i];
			if (iR<0 || iR>iN - 1 || iC<0 || iC>iM - 1)
			{
				++iExitCount;
				continue;
			}
			if (matWorld[iR][iC]) continue;
			vecNext[j].first = iR;
			vecNext[j].second = iC;

		}
		if (iExitCount == 1)
		{
			iAns = min(iAns, iK);
			return;
		}
		FindWay(iK + 1, vecNext);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> iN >> iM;

	vector<pair<int, int>> vecPos;
	for (int i = 0;i < iN;++i)
	{
		string strMap;
		cin >> strMap;
		for (int j = 0;j < iM;++j)
		{
			if (strMap[j] == '#') matWorld[i][j] = true;
			if (strMap[j] == 'o') vecPos.push_back({ i,j });
		}
	}

	FindWay(1, vecPos);
	if (iAns == 2147483647) iAns = -1;
	cout << iAns << "\n";
	return 0;
}
