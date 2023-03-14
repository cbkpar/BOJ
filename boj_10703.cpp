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
	vector<string> vecMap(iN);
	for (int i = 0; i < iN; ++i) cin >> vecMap[i];

	int iMax = 100000;
	for (int i = 0; i < iM; ++i)
	{
		int iHeight = -1;
		int iGround = iN - 1;
		for (int j = 0; j < iN; ++j)
		{
			if (vecMap[j][i] == 'X')
			{
				iHeight = j;
			}
			else if (vecMap[j][i] == '#')
			{
				iGround = j;
				break;
			}
		}
		if (iHeight != -1)
		{
			iMax = min(iMax, iGround - iHeight - 1);
		}
	}
	for (int i = 0; i < iM; ++i)
	{
		for (int j = iN - 1; j >= 0; --j)
		{
			if (vecMap[j][i] == 'X')
			{
				vecMap[j][i] = '.';
				vecMap[j + iMax][i] = 'X';
			}
		}
	}
	for (int i = 0; i < iN; ++i) cout << vecMap[i] << "\n";
	return 0;
}
