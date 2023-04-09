#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

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
		int iN;
		cin >> iN;
		pair<long long, long long> Pos;
		vector<pair<long long, long long>> vecPos;

		for (int i = 0; i < iN; ++i)
		{
			string strCode;
			cin >> strCode;
			for (int j = 0; j < iN; ++j)
			{
				if (strCode[j] == 'p')
				{
					vecPos.push_back({ i,j });
				}
				else if (strCode[j] == 's')
				{
					Pos = { i,j };
				}
			}
		}

		long long lMax = 1LL << 62;
		int iIndex = 0;
		int iSize = vecPos.size();
		for (int i = 0; i < iSize; ++i)
		{
			long long lDiffX = (vecPos[i].first - Pos.first);
			long long lDiffY = (vecPos[i].second - Pos.second);
			if (lMax > lDiffX * lDiffX + lDiffY * lDiffY)
			{
				lMax = lDiffX * lDiffX + lDiffY * lDiffY;
				iIndex = i;
			}
		}
		cout << "(" << Pos.first << "," << Pos.second << "):";
		cout << "(" << vecPos[iIndex].first << "," << vecPos[iIndex].second << "):";

		cout << fixed;
		cout.precision(2);
		cout << sqrt((double)(lMax)) << "\n";
	}
	return 0;
}
