#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int dR[8] = { -1,-1,-1,0,0,1,1,1 };
int dC[8] = { -1,0,1,-1,1,-1,0,1 };

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

		vector<string> vecMap(iN, "");
		for (int i = 0; i < iN; ++i)
		{
			cin >> vecMap[i];
		}

		if (iN <= 2)
		{
			cout << "0\n";
			continue;
		}

		int iAns = 0;

		if (iN > 4)
		{
			iAns += (iN - 4) * (iN - 4);
		}

		for (int i = 0; i < iN - 2; ++i)
		{
			if (vecMap[0][i] >= '1')
			{
				++iAns;
				for (int j = 0; j < 8; ++j)
				{
					int iNextR = 1 + dR[j];
					int iNextC = i + 1 + dC[j];
					--vecMap[iNextR][iNextC];
				}
			}
		}
		for (int i = 0; i < iN - 2; ++i)
		{
			if (vecMap[i][iN - 1] >= '1')
			{
				++iAns;
				for (int j = 0; j < 8; ++j)
				{
					int iNextR = i + 1 + dR[j];
					int iNextC = iN - 2 + dC[j];
					--vecMap[iNextR][iNextC];
				}
			}
		}
		for (int i = 0; i < iN - 2; ++i)
		{
			if (vecMap[i][0] >= '1')
			{
				++iAns;
				for (int j = 0; j < 8; ++j)
				{
					int iNextR = i + 1 + dR[j];
					int iNextC = 1 + dC[j];
					--vecMap[iNextR][iNextC];
				}
			}
		}
		for (int i = 0; i < iN - 2; ++i)
		{
			if (vecMap[iN - 1][i] >= '1')
			{
				++iAns;
				for (int j = 0; j < 8; ++j)
				{
					int iNextR = iN - 2 + dR[j];
					int iNextC = i + 1 + dC[j];
					--vecMap[iNextR][iNextC];
				}
			}
		}
		cout << iAns << "\n";
	}
	return 0;
}
