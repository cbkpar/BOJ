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

	vector<string> vecMap(iN, "");
	for (int i = 0; i < iN; ++i) cin >> vecMap[i];

	vector<vector<bool>> vecPark(iN, vector<bool>(iM, false));
	for (int i = 0; i < iN; ++i)
	{
		int iNow = 0;
		while (iNow < iM)
		{
			if (vecMap[i][iNow] == 'o') break;
			vecPark[i][iNow] = true;
			++iNow;
		}
	}

	for (int i = 0; i < iN; ++i)
	{
		int iNow = iM - 1;
		while (iNow > 0)
		{
			if (vecMap[i][iNow] == 'o') break;
			vecPark[i][iNow] = true;
			--iNow;
		}
	}

	for (int i = 0; i < iM; ++i)
	{
		int iNow = 0;
		while (iNow < iN)
		{
			if (vecMap[iNow][i] == 'o') break;
			vecPark[iNow][i] = true;
			++iNow;
		}
	}

	for (int i = 0; i < iM; ++i)
	{
		int iNow = iN - 1;
		while (iNow > 0)
		{
			if (vecMap[iNow][i] == 'o') break;
			vecPark[iNow][i] = true;
			--iNow;
		}
	}

	int iSum = 0;
	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iM; ++j)
		{
			if (vecPark[i][j])
			{
				++iSum;
			}
		}
	}

	cout << iSum << "\n";
	return 0;
}
