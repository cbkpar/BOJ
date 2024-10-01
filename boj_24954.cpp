#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int iAns = 999999999;
int iN;

bool arrVisited[11] = { false, };
int vecP[11] = { 0, };
int arrN[10] = { 0, };
vector<vector<pair<int, int>>> vecSale;

void dfs(int iNum)
{
	if (iNum == iN)
	{
		vector<int> vecTempP(iN + 1, 0);
		for (int i = 1;i <= iN;++i)
		{
			vecTempP[i] = vecP[i];
		}
		int iNow = 0;

		for (int i = 0;i < iN;++i)
		{
			iNow += vecTempP[arrN[i]];

			int iSize = vecSale[arrN[i]].size();
			for (int j = 0;j < iSize;++j)
			{
				vecTempP[vecSale[arrN[i]][j].first] -= vecSale[arrN[i]][j].second;
				if (vecTempP[vecSale[arrN[i]][j].first] < 1)
				{
					vecTempP[vecSale[arrN[i]][j].first] = 1;
				}
			}
		}

		iAns = min(iAns, iNow);
		return;
	}

	for (int i = 1;i <= iN;++i)
	{
		if (arrVisited[i]) continue;
		arrVisited[i] = true;
		arrN[iNum] = i;
		dfs(iNum + 1);
		arrVisited[i] = false;
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> iN;

	for (int i = 1;i <= iN;++i)
	{
		cin >> vecP[i];
	}

	vecSale = vector<vector<pair<int, int>>>(iN + 1, vector<pair<int, int>>());
	for (int i = 1;i <= iN;++i)
	{
		int iCount;
		cin >> iCount;
		for (int j = 0;j < iCount;++j)
		{
			int iNum, iPrice;
			cin >> iNum >> iPrice;
			vecSale[i].push_back({ iNum,iPrice });
		}
	}

	dfs(0);

	cout << iAns << "\n";
	return 0;
}
