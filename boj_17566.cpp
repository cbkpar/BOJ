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

	int iM, iB, iS;
	cin >> iM >> iB >> iS;

	vector<string> vecMap(iB, "");
	for (int i = 0;i < iB;++i)
	{
		cin >> vecMap[i];
	}

	vector<bool> vecVisited(iS, false);
	for (int i = 0;i < iB;++i)
	{
		if (vecMap[i][iM - 1] == '1')
		{
			for (int j = 0;j < iS;++j)
			{
				if (vecMap[i][j] == '1')
				{
					vecVisited[j] = true;
				}
			}
		}
	}

	int iAns = 0;
	for (int i = 0;i < iS;++i)
	{
		if (i == iM - 1) continue;
		if (vecVisited[i])
		{
			++iAns;
		}
	}

	cout << iAns << "\n";
	return 0;
}
