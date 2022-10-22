#include <iostream>

using namespace std;

int arrNumber[10001] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	arrNumber[0] = -1;

	int iTest;
	cin >> iTest;
	for (int iT = 1; iT <= iTest; ++iT)
	{
		int iN, iK;
		cin >> iN >> iK;
		int iSize = 1;
		for (int i = 0; i < iN; ++i)
		{
			int iNumber;
			cin >> iNumber;
			if (arrNumber[iSize - 1] < iNumber)
			{
				arrNumber[iSize++] = iNumber;
			}
			else
			{
				int iLeft = 0;
				int iRight = iSize - 1;
				while (iLeft < iRight)
				{
					int iMid = (iLeft + iRight) / 2;
					if (arrNumber[iMid] < iNumber)
					{
						iLeft = iMid + 1;
					}
					else
					{
						iRight = iMid;
					}
				}
				arrNumber[iLeft] = iNumber;
			}
		}
		cout << "Case #" << iT << "\n";
		cout << ((iSize - 1) >= iK ? 1 : 0) << "\n";
	}
	return 0;
}
