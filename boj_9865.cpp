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
	for (int t = 1; t <= iT; ++t)
	{
		int iScoreA = 0;
		int iScoreB = 0;

		int iGame;
		cin >> iGame;

		while (iGame--)
		{
			int iNumA, iNumB;
			cin >> iNumA >> iNumB;
			if (iNumA > iNumB)
			{
				if (iNumA - 1 == iNumB)
				{
					iScoreB += iNumA + iNumB;
					if (iNumA + iNumB == 3) iScoreB += 3;
				}
				else
				{
					iScoreA += iNumA;
				}
			}
			if (iNumB > iNumA)
			{
				if (iNumB - 1 == iNumA)
				{
					iScoreA += iNumA + iNumB;
					if (iNumA + iNumB == 3) iScoreA += 3;
				}
				else
				{
					iScoreB += iNumB;
				}
			}
		}
		cout << "Game " << t << ": Tessa " << iScoreA << " Danny " << iScoreB << "\n";
	}
	return 0;
}
