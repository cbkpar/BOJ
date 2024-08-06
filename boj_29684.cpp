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
		int iT;
		cin >> iT;
		if (iT == 0) break;

		int iDiffMax = 100000;
		int iAns = -1;

		for (int t = 1;t <= iT;++t)
		{
			int iNum;
			cin >> iNum;

			int iDiff = abs(iNum - 2023);
			if (iDiff < iDiffMax)
			{
				iDiffMax = iDiff;
				iAns = t;
			}
		}

		cout << iAns << "\n";
	}
	return 0;
}
