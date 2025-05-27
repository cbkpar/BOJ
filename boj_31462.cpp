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

	int iN;
	cin >> iN;

	vector<string> vecLine(iN, "");
	for (int i = 0;i < iN;++i)
	{
		cin >> vecLine[i];
	}

	int iCount = 0;
	for (int i = 0;i < iN;++i)
	{
		for (int j = 0;j <= i;++j)
		{
			if (vecLine[i][j] == 'R')
			{
				if (i < iN - 1)
				{
					if (vecLine[i + 1][j] == 'R' && vecLine[i + 1][j + 1] == 'R')
					{
						iCount += 3;
						vecLine[i][j] = '-';
						vecLine[i + 1][j] = '-';
						vecLine[i + 1][j + 1] = '-';
					}
				}
			}
			if (vecLine[i][j] == 'B')
			{
				if (i < iN - 1 && j < i)
				{
					if (vecLine[i][j + 1] == 'B' && vecLine[i + 1][j + 1] == 'B')
					{
						iCount += 3;
						vecLine[i][j] = '-';
						vecLine[i][j + 1] = '-';
						vecLine[i + 1][j + 1] = '-';
					}
				}
			}
		}
	}
	if (iCount == iN * (iN + 1) / 2)
	{
		cout << "1" << "\n";
	}
	else
	{
		cout << "0" << "\n";
	}
	return 0;
}
