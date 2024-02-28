#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;

	vector<string> vecN(iN, "");
	vector<string> vecM(iM, "");

	for (int i = 0;i < iN;++i) cin >> vecN[i];
	for (int i = 0;i < iM;++i) cin >> vecM[i];

	for (int i = 0;i < iN;++i)
	{
		for (int j = 0;j < iM;++j)
		{
			int iCount = 0;
			for (int p = 0;p < iN;++p)
			{
				if (p == i) continue;
				bool bPossible = true;
				for (int t = 0;t < 25;++t)
				{
					if (vecN[i][t] != vecN[p][t] && vecM[j][t] != vecN[p][t])
					{
						bPossible = false;
					}
				}
				if (bPossible) ++iCount;
			}

			for (int q = 0;q < iM;++q)
			{
				if (q == j) continue;
				bool bPossible = true;
				for (int t = 0;t < 25;++t)
				{
					if (vecN[i][t] != vecM[q][t] && vecM[j][t] != vecM[q][t])
					{
						bPossible = false;
					}
				}
				if (bPossible) ++iCount;
			}
			cout << iCount << (j == iM-1 ? "" : " ");
		}
		cout << "\n";
	}
	return 0;
}
