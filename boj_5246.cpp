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
		int iN;
		cin >> iN;
		vector<int> vecRow(9, 0);
		vector<int> vecCol(9, 0);

		for (int i = 0; i < iN; ++i)
		{
			int iR, iC;
			cin >> iR >> iC;
			++vecRow[iR];
			++vecCol[iC];
		}
		int iMax = 0;
		for (int i = 1; i <= 8; ++i)
		{
			iMax = max(iMax, vecCol[i]);
		}
		cout << iMax << "\n";
	}
	return 0;
}
