#include <iostream>
#include <string>

using namespace std;

int mapNumber[50][50] = { 0, };
int dR[8] = { -1, -1 ,-1, 0, 0, 1, 1, 1 };
int dC[8] = { -1, 0 ,1 ,-1 ,1 ,-1, 0, 1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iR, iS;
	cin >> iR >> iS;

	for (int i = 0; i < iR; ++i)
	{
		string strMap;
		cin >> strMap;
		for (int j = 0; j < iS; ++j)
		{
			if (strMap[j] == 'o')
			{
				mapNumber[i][j] = 1;
			}
		}
	}

	int iCount = 0;
	int iMaxCount = 0;
	for (int i = 0; i < iR; ++i)
	{
		for (int j = 0; j < iS; ++j)
		{
			if (mapNumber[i][j] == 1)
			{
				for (int k = 0; k < 8; ++k)
				{
					int iNowR = i + dR[k];
					int iNowC = j + dC[k];
					if (iNowR < 0 || iNowR > iR - 1 || iNowC < 0 || iNowC > iS - 1) continue;
					if (mapNumber[iNowR][iNowC] == 1) ++iCount;
				}
			}
			else
			{
				int iTempCount = 0;
				for (int k = 0; k < 8; ++k)
				{
					int iNowR = i + dR[k];
					int iNowC = j + dC[k];
					if (iNowR < 0 || iNowR > iR - 1 || iNowC < 0 || iNowC > iS - 1) continue;
					if (mapNumber[iNowR][iNowC] == 1) ++iTempCount;
				}
				if (iTempCount > iMaxCount) iMaxCount = iTempCount;
			}
		}
	}
	cout << ((iCount / 2) + iMaxCount) << "\n";
	return 0;
}
