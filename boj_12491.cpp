#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	int iT;
	cin >> iT;

	for (int t = 1;t <= iT;++t)
	{
		int iR, iC;
		cin >> iR >> iC;
		vector<string> vecLine(iR, "");
		for (int i = 0;i < iR;++i)
		{
			cin >> vecLine[i];
		}

		bool bPossible = true;
		for (int i = 0;i < iR;++i)
		{
			for (int j = 0;j < iC;++j)
			{
				if (vecLine[i][j] == '#')
				{
					if (i == iR - 1 || j == iC - 1)
					{
						bPossible = false;
						break;
					}
					if (vecLine[i][j + 1] == '#' && vecLine[i + 1][j] == '#' && vecLine[i + 1][j + 1] == '#')
					{
						vecLine[i][j] = '/';
						vecLine[i][j + 1] = '\\';
						vecLine[i + 1][j] = '\\';
						vecLine[i + 1][j + 1] = '/';
					}
					else
					{
						bPossible = false;
						break;
					}
				}
			}
		}

		cout << "Case #" << t << ":" << "\n";
		if (bPossible)
		{
			for (int i = 0;i < iR;++i)
			{
				for (int j = 0;j < iC;++j)
				{
					cout << vecLine[i][j];
				}
				cout << "\n";
			}
		}
		else
		{
			cout << "Impossible" << "\n";
		}
	}

	return 0;
}
