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

	int iN, iM, iK;
	cin >> iN >> iM >> iK;

	vector<string> vecWord(iN, "");
	for (int i = 0; i < iN; ++i)
	{
		cin >> vecWord[i];
	}

	vector<vector<char>> vecAns(iK, vector<char>(iK, ' '));
	int iCount = 0;

	for (int i = 0; i < iK; ++i)
	{
		for (int j = 0; j < iK; ++j)
		{
			vector<int> vecCount(26, 0);
			for (int p = i; p < iN; p += iK)
			{
				for (int q = j; q < iM; q += iK)
				{
					++vecCount[vecWord[p][q] - 'A'];
				}
			}
			int iMax = -1;
			int iIndex = 0;
			for (int k = 0; k < 26; ++k)
			{
				if (vecCount[k] > iMax)
				{
					iMax = vecCount[k];
					iIndex = k;
				}
			}
			iCount += (iN / iK) * (iM / iK) - iMax;
			vecAns[i][j] = (char)(iIndex + 'A');
		}
	}
	cout << iCount << "\n";
	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iM; ++j)
		{
			cout << vecAns[i % iK][j % iK];
		}
		cout << "\n";
	}
	return 0;
}
