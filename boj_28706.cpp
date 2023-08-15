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

	int iT;
	cin >> iT;
	while (iT--)
	{
		vector<bool> vecVisited(7, false);
		vecVisited[1] = true;

		int iN;
		cin >> iN;
		while (iN--)
		{
			vector<bool> vecNext(7, false);
			string strCommand;
			int iNum;
			for (int t = 0; t < 2; ++t)
			{
				cin >> strCommand >> iNum;
				if (strCommand[0] == '+')
				{
					for (int i = 0; i < 7; ++i)
					{
						if (vecVisited[i])
						{
							vecNext[(i + iNum) % 7] = true;
						}
					}
				}
				else
				{
					for (int i = 0; i < 7; ++i)
					{
						if (vecVisited[i])
						{
							vecNext[(i * iNum) % 7] = true;
						}
					}
				}
			}
			for (int i = 0; i < 7; ++i)
			{
				vecVisited[i] = vecNext[i];
			}
		}
		cout << (vecVisited[0] ? "LUCKY" : "UNLUCKY") << "\n";
	}
	return 0;
}
