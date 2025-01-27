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

	vector<string> vecLine(iN * 3, "");
	for (int i = 0; i < iN * 3; ++i)
	{
		cin >> vecLine[i];
	}

	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iM; ++j)
		{
			if ((i + j) % 2 == 1)
			{
				bool bAdd = false;
				if (i > 0)
				{
					if (vecLine[i * 3 - 1][j * 3 + 1] == '#')
					{
						vecLine[i * 3][j * 3 + 1] = '#';
						bAdd = true;
					}
				}
				if (i < iN - 1)
				{
					if (vecLine[i * 3 + 3][j * 3 + 1] == '#')
					{
						vecLine[i * 3 + 2][j * 3 + 1] = '#';
						bAdd = true;
					}
				}

				if (j > 0)
				{
					if (vecLine[i * 3 + 1][j * 3 - 1] == '#')
					{
						vecLine[i * 3 + 1][j * 3] = '#';
						bAdd = true;
					}
				}
				if (j < iM - 1)
				{
					if (vecLine[i * 3 + 1][j * 3 + 3] == '#')
					{
						vecLine[i * 3 + 1][j * 3 + 2] = '#';
						bAdd = true;
					}
				}

				if (bAdd)
				{
					vecLine[i * 3 + 1][j * 3 + 1] = '#';
				}
			}
		}
	}
	for (int i = 0; i < iN * 3; ++i)
	{
		for (int j = 0; j < iM * 3; ++j)
		{
			cout << vecLine[i][j];
		}
		cout << "\n";
	}

	return 0;
}
