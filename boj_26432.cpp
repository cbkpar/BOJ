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
		int iN, iM, iP;
		cin >> iN >> iM >> iP;

		vector<vector<int>> vecNum(iN, vector<int>(iM, 0));
		for (int i = 0; i < iN; ++i)
		{
			for (int j = 0; j < iM; ++j)
			{
				cin >> vecNum[i][j];
			}
		}

		int iAns = 0;
		for (int i = 0; i < iM; ++i)
		{
			int iMax = 0;
			for (int j = 0; j < iN; ++j)
			{
				iMax = max(iMax, vecNum[j][i]);
			}
			iAns += iMax - vecNum[iP - 1][i];
		}
		cout << "Case #" << t << ": ";
		cout << iAns << "\n";
	}
	return 0;
}
