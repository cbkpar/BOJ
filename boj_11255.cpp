#include <iostream>
#include <vector>
#include <algorithm>

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

		int iN, iM, iK;
		cin >> iN >> iM >> iK;

		vector<int> vecNum(iN + 1, 0);
		vector<vector<int>> vecNode(iN + 1, vector<int>());
		vector<bool> vecVisited(iN + 1, false);

		for (int i = 0;i < iM;++i)
		{
			int iS, iE;
			cin >> iS >> iE;
			vecNode[iS].push_back(iE);
			vecNode[iE].push_back(iS);
		}

		for (int i = 0;i < iK;++i)
		{
			int iNow;
			cin >> iNow;
			vecVisited[iNow] = true;

			for (int iNext : vecNode[iNow])
			{
				vecVisited[iNext] = true;
			}
		}

		int iAns = 0;
		for (int i = 1;i <= iN;++i)
		{
			if (vecVisited[i])
			{
				++iAns;
			}
		}
		cout << iAns << "\n";
	}
	
	return 0;
}
