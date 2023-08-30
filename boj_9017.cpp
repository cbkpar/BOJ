#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	while (iT--)
	{
		vector<vector<int>> vecTeam(201, vector<int>());

		int iN;
		cin >> iN;
		vector<int> vecCount(201, 0);
		vector<int> vecRank(iN, 0);
		for (int i = 0; i < iN; ++i)
		{
			cin >> vecRank[i];
			++vecCount[vecRank[i]];
		}
		int iIndex = 1;
		for (int i = 0; i < iN; ++i)
		{
			if (vecCount[vecRank[i]] == 6)
			{
				vecTeam[vecRank[i]].push_back(iIndex++);
			}
		}

		int iAns = -1;
		int iSum = 100000;
		int iMax = 1000;
		for (int i = 1; i <= 200; ++i)
		{
			if (vecTeam[i].size() == 6)
			{
				int iTempSum = 0;
				for (int j = 0; j < 4; ++j) iTempSum += vecTeam[i][j];

				if (iSum == iTempSum)
				{
					if (iMax > vecTeam[i][4])
					{
						iMax = vecTeam[i][4];
						iAns = i;
					}
				}
				else if (iSum > iTempSum)
				{
					iSum = iTempSum;
					iMax = vecTeam[i][4];
					iAns = i;
				}
			}
		}
		cout << iAns << "\n";
	}
	return 0;
}
