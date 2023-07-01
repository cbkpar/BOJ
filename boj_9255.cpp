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

	for (int t = 1; t <= iT; ++t)
	{
		int iN, iM;
		cin >> iN >> iM;
		vector<vector<int>> vecNode(iN + 1, vector<int>());
		while (iM--)
		{
			int iS, iE;
			cin >> iS >> iE;
			vecNode[iS].push_back(iE);
			vecNode[iE].push_back(iS);
		}

		int iStart;
		cin >> iStart;
		sort(vecNode[iStart].begin(), vecNode[iStart].end());

		if (t > 1) cout << "\n";
		cout << "Data Set " << t << ":\n";
		int iSize = vecNode[iStart].size();
		for (int i = 0; i < iSize; ++i)
		{
			if (i > 0 && vecNode[iStart][i - 1] == vecNode[iStart][i]) continue;
			cout << (i > 0 ? " " : "") << vecNode[iStart][i];
		}
		cout << "\n";
	}
	return 0;
}
