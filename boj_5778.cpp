#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true)
	{
		int iN, iM;
		cin >> iN >> iM;
		if (iN == 0 && iM == 0) break;

		int iAns = 0;
		vector<int> vecVisited(iN + 1, 0);
		for (int i = 0; i < iM; ++i)
		{
			int iNum;
			cin >> iNum;
			if (++vecVisited[iNum] == 2)
			{
				++iAns;
			}
		}
		cout << iAns << "\n";
	}
	return 0;
}
