#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dX[8] = { 0,-1,-1,-1,0,1,1,1 };
int dY[8] = { -1,-1,0,1,1,1,0,-1 };

int g_iAns = 0;

void dfs(vector<vector<pair<int, int>>> matMap, int iSum)
{
	g_iAns = max(g_iAns, iSum);

	//Fish Move
	for (int k = 1; k <= 16; ++k)
	{
		bool bFound = false;
		for (int i = 0; i < 4; ++i)
		{
			if (bFound) break;
			for (int j = 0; j < 4; ++j)
			{
				if (bFound) break;
				if (matMap[i][j].first == k)
				{
					for (int t = 0; t < 8; ++t)
					{
						int iNextY = i + dY[(matMap[i][j].second + t) % 8];
						int iNextX = j + dX[(matMap[i][j].second + t) % 8];
						if (iNextX < 0 || iNextX > 3 || iNextY < 0 || iNextY > 3) continue;
						if (matMap[iNextY][iNextX].first < 0) continue;
						matMap[i][j].second = (matMap[i][j].second + t) % 8;
						swap(matMap[i][j], matMap[iNextY][iNextX]);
						bFound = true;
						break;
					}
				}
			}
		}
	}

	//Shark Move
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (matMap[i][j].first == -1)
			{
				for (int t = 1; t <= 4; ++t)
				{
					int iNextY = i + dY[matMap[i][j].second] * t;
					int iNextX = j + dX[matMap[i][j].second] * t;
					if (iNextX < 0 || iNextX > 3 || iNextY < 0 || iNextY > 3) continue;
					if (matMap[iNextY][iNextX].first <= 0) continue;
					swap(matMap[i][j].first, matMap[iNextY][iNextX].first);
					int iTempNum = matMap[i][j].first;
					matMap[i][j].first = 0;
					int iTempSum = iSum + iTempNum;
					dfs(matMap, iTempSum);
					matMap[i][j].first = iTempNum;
					swap(matMap[i][j].first, matMap[iNextY][iNextX].first);
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<vector<pair<int, int>>> matMap(4, vector<pair<int, int>>(4, { 0,0 }));

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			cin >> matMap[i][j].first >> matMap[i][j].second;
			--matMap[i][j].second;
		}
	}

	int iTempSum = matMap[0][0].first;
	matMap[0][0].first = -1;
	dfs(matMap, iTempSum);

	cout << g_iAns << "\n";
	return 0;
}
