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

	while (true)
	{
		int iN, iM, iR, iC;
		cin >> iN >> iM >> iR >> iC;
		if (iN == 0 && iM == 0 && iR == 0 && iC == 0) break;

		vector<string> vecMap(iN, "");
		for (int i = 0; i < iN; ++i) cin >> vecMap[i];

		int iCount = 0;
		for (int i = 0; i <= iN - iR; ++i)
		{
			for (int j = 0; j <= iM - iC; ++j)
			{
				if (vecMap[i][j] == '1')
				{
					++iCount;
					for (int p = 0; p < iR; ++p)
					{
						for (int q = 0; q < iC; ++q)
						{
							vecMap[i + p][j + q] = (vecMap[i + p][j + q] == '1' ? '0' : '1');
						}
					}
				}
			}
		}

		bool bPossible = true;
		for (int i = 0; i < iN; ++i)
		{
			for (int j = 0; j < iM; ++j)
			{
				if (vecMap[i][j] == '1')
				{
					bPossible = false;
				}
			}
		}

		if (bPossible)
		{
			cout << iCount << "\n";
		}
		else
		{
			cout << "-1" << "\n";
		}
	}

	return 0;
}
