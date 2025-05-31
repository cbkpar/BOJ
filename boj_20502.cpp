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

	vector<int> vecRank(iN + 1, 0);
	for (int i = 1; i <= iN; ++i)
	{
		cin >> vecRank[i];
	}
	vector<vector<pair<int, int>>> vecKeyword(iM + 1, vector<pair<int, int>>());

	for (int i = 1; i <= iN; ++i)
	{
		int iK;
		cin >> iK;
		while (iK-- > 0)
		{
			int iNum;
			cin >> iNum;
			vecKeyword[iNum].push_back({ vecRank[i], i });
		}
	}
	for (int i = 1; i <= iM; ++i)
	{
		sort(vecKeyword[i].begin(), vecKeyword[i].end());
	}

	int iQ;
	cin >> iQ;
	while (iQ-- > 0)
	{
		int iNum;
		cin >> iNum;

		int iSize = vecKeyword[iNum].size();
		if (iSize == 0)
		{
			cout << "-1" << "\n";
		}
		else
		{
			for (int i = 0; i < iSize; ++i)
			{
				cout << vecKeyword[iNum][i].second << (i == iSize - 1 ? "\n" : " ");
			}
		}
	}
	return 0;
}
