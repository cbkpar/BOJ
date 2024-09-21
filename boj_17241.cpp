#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM, iQ;
	cin >> iN >> iM >> iQ;

	vector<vector<int>> vecNode(iN + 1, vector<int>());
	for (int i = 0;i < iM;++i)
	{
		int iS, iE;
		cin >> iS >> iE;
		vecNode[iS].push_back(iE);
		vecNode[iE].push_back(iS);
	}

	vector<bool> vecVisited(iN + 1, false);
	vector<bool> vecAdded(iN + 1, false);

	while (iQ-- > 0)
	{
		int iNum;
		cin >> iNum;

		if (vecVisited[iNum])
		{
			cout << "0" << "\n";
			continue;
		}

		vecVisited[iNum] = true;

		int iCount = 0;
		if (!vecAdded[iNum])
		{
			++iCount;
			vecAdded[iNum] = true;
		}
		for (int iNext : vecNode[iNum])
		{
			if (!vecAdded[iNext])
			{
				++iCount;
				vecAdded[iNext] = true;
			}
		}
		cout << iCount << "\n";
	}

	return 0;
}
