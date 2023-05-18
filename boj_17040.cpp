#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;

	vector<int> vecNum(iN + 1, 1);
	vector<vector<int>> vecNode(iN + 1, vector<int>());
	for (int i = 0; i < iM; ++i)
	{
		int iS, iE;
		cin >> iS >> iE;
		if (iS > iE) swap(iS, iE);
		vecNode[iE].push_back(iS);
	}

	for (int i = 1; i <= iN; ++i)
	{
		vector<bool> vecVisited(5, false);
		for (int iNext : vecNode[i])
		{
			vecVisited[vecNum[iNext]] = true;
		}
		for (int j = 1; j <= 4; ++j)
		{
			if (!vecVisited[j])
			{
				vecNum[i] = j;
				cout << j;
				break;
			}
		}
	}
	cout << "\n";
	return 0;
}
