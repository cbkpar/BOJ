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
		int iN;
		cin >> iN;
		if (iN == 0) break;

		int iCount = 0;
		if (iN % 2 == 1)
		{
			++iCount;
			++iN;
		}

		iN /= 2;

		int iLeft = 1;
		int iRight = 50;

		while (true)
		{
			++iCount;
			int iMid = (iLeft + iRight) / 2;
			if (iMid == iN) break;
			if (iMid < iN)
			{
				iLeft = iMid + 1;
			}
			else
			{
				iRight = iMid - 1;
			}
		}
		cout << iCount << "\n";
	}

	return 0;
}
