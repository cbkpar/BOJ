#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int dR[4] = { -1,0,1,0 };
int dC[4] = { 0,-1,0,1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iH, iW;
	cin >> iH >> iW;

	vector<vector<int>> matMap(iH, vector<int>(iW, 0));

	vector<vector<int>> matCountPrincess(iH, vector<int>(iW, 1000000000));
	vector<vector<int>> matCountSoilder(iH, vector<int>(iW, 1000000000));

	queue<pair<int, int>> qPrincess;
	queue<pair<int, int>> qSoilder;
	pair<int, int> pExit;

	for (int i = 0; i < iH; ++i)
	{
		string strMap;
		cin >> strMap;
		for (int j = 0; j < iW; ++j)
		{
			if (strMap[j] == '@')
			{
				qPrincess.push({ i,j });
				matCountPrincess[i][j] = 0;
			}
			else if (strMap[j] == '$')
			{
				qSoilder.push({ i,j });
				matCountSoilder[i][j] = 0;
			}
			else if (strMap[j] == '%')
			{
				pExit.first = i;
				pExit.second = j;
			}
			else if (strMap[j] == '#')
			{
				matMap[i][j] = 1;
			}
		}
	}
	
	int iCount = 0;
	while (!qPrincess.empty())
	{
		int iSize = qPrincess.size();
		++iCount;
		while (iSize--)
		{
			pair<int, int> pNow = qPrincess.front();
			qPrincess.pop();
			for (int i = 0; i < 4; ++i)
			{
				pair<int, int> pNext;
				pNext.first = pNow.first + dR[i];
				pNext.second = pNow.second + dC[i];
				if (pNext.first < 0 || pNext.first > iH - 1 || pNext.second < 0 || pNext.second > iW - 1) continue;
				if (matMap[pNext.first][pNext.second] == 1) continue;
				if (matCountPrincess[pNext.first][pNext.second] == 1000000000)
				{
					matCountPrincess[pNext.first][pNext.second] = iCount;
					qPrincess.push(pNext);
				}
			}
		}
	}

	iCount = 0;
	while (!qSoilder.empty())
	{
		int iSize = qSoilder.size();
		++iCount;
		while (iSize--)
		{
			pair<int, int> pNow = qSoilder.front();
			qSoilder.pop();
			for (int i = 0; i < 4; ++i)
			{
				pair<int, int> pNext;
				pNext.first = pNow.first + dR[i];
				pNext.second = pNow.second + dC[i];
				if (pNext.first < 0 || pNext.first > iH - 1 || pNext.second < 0 || pNext.second > iW - 1) continue;
				if (matMap[pNext.first][pNext.second] == 1) continue;
				if (matCountSoilder[pNext.first][pNext.second] == 1000000000)
				{
					matCountSoilder[pNext.first][pNext.second] = iCount;
					qSoilder.push(pNext);
				}
			}
		}
	}

	if (matCountPrincess[pExit.first][pExit.second] < matCountSoilder[pExit.first][pExit.second])
	{
		cout << "Yes\n";
	}
	else
	{
		cout << "No\n";
	}
	return 0;
}
