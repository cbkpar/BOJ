#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	vector<int> vecUse(1440, 0);
	while (iN--)
	{
		int iS, iE;
		cin >> iS >> iE;

		iS = (iS / 100) * 60 + iS % 100 - 10;
		iE = (iE / 100) * 60 + iE % 100 + 10;
		if (iS < 0) iS = 0;
		if (iE > 1440) iE = 1441;
		for (int i = iS; i < iE; ++i)
		{
			++vecUse[i];
		}
	}

	int iAns = 0;
	int iCount = 0;
	for (int i = 600; i < 1320; ++i)
	{
		if (vecUse[i] == 0)
		{
			++iCount;
		}
		else
		{
			iCount = 0;
		}
		iAns = max(iAns, iCount);
	}

	cout << iAns << "\n";
	return 0;
}
