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

	int iN;
	cin >> iN;
	vector<string> vecName(iN, "");
	for (int i = 0; i < iN; ++i) cin >> vecName[i];

	int iAns = 0;
	for (int i = 0; i < iN; ++i)
	{
		for (int j = i + 1; j < iN; ++j)
		{
			bool bLink = false;
			int iSizeA = vecName[i].length();
			int iSizeB = vecName[j].length();
			int iSizeMin = min(iSizeA, iSizeB);
			for (int k = 0; k < iSizeMin; ++k)
			{
				for (int p = 0; p <= k; ++p)
				{
					if (vecName[i][iSizeA - 1 - k + p] != vecName[j][p]) break;
					if (p == k) bLink = true;
				}
				for (int p = 0; p <= k; ++p)
				{
					if (vecName[j][iSizeB - 1 - k + p] != vecName[i][p]) break;
					if (p == k) bLink = true;
				}
			}
			if (bLink) ++iAns;
		}
	}
	cout << iAns << "\n";
	return 0;
}
