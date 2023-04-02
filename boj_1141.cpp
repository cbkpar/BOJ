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
	vector<string> vecWord(iN, "");
	vector<bool> vecUsed(iN, true);

	for (int i = 0; i < iN; ++i)
	{
		cin >> vecWord[i];
	}

	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iN; ++j)
		{
			if (i == j) continue;
			int iSizeA = vecWord[i].length();
			int iSizeB = vecWord[j].length();
			if (iSizeA > iSizeB) continue;
			for (int k = 0; k < iSizeA; ++k)
			{
				if (vecWord[i][k] != vecWord[j][k]) break;
				if (k == iSizeA - 1)
				{
					if (iSizeA == iSizeB)
					{
						if (j > i) vecUsed[j] = false;
					}
					else
					{
						vecUsed[i] = false;
					}
				}
			}
		}
	}

	int iAns = 0;
	for (int i = 0; i < iN; ++i) if (vecUsed[i]) ++iAns;
	cout << iAns << "\n";
	return 0;
}
