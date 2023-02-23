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
		int iN, iK, iT, iM;
		cin >> iN >> iK >> iT >> iM;
		vector<vector<int>> matScore(iN, vector<int>(iK, 0));
		vector<int> vecScore(iN, 0);
		vector<int> vecCount(iN, 0);
		vector<int> vecCommit(iN, 0);
		for (int i = 0; i < iM; ++i)
		{
			int iTeam, iLevel, iScore;
			cin >> iTeam >> iLevel >> iScore;
			vecCommit[iTeam - 1] = i;
			++vecCount[iTeam - 1];
			matScore[iTeam - 1][iLevel - 1] = max(matScore[iTeam - 1][iLevel - 1], iScore);
		}
		for (int i = 0; i < iN; ++i)
		{
			for (int j = 0; j < iK; ++j)
			{
				vecScore[i] += matScore[i][j];
			}
		}
		int iRank = 1;
		for (int i = 0; i < iN; ++i)
		{
			if (i == iT - 1) continue;
			if (vecScore[i] > vecScore[iT - 1])
			{
				++iRank;
			}
			else if (vecScore[i] == vecScore[iT - 1])
			{
				if (vecCount[i] < vecCount[iT - 1])
				{
					++iRank;
				}
				else if (vecCount[i] == vecCount[iT - 1])
				{
					if (vecCommit[i] < vecCommit[iT - 1])
					{
						++iRank;
					}
				}
			}
		}
		cout << iRank << "\n";
	}
	return 0;
}
