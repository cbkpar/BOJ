#include <iostream>

using namespace std;

int arrNumber[40001] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	arrNumber[0] = -1;

	int iT;
	cin >> iT;
	while (iT--)
	{
		int iN;
		cin >> iN;
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
		cout << (iSize - 1) << "\n";
	}
	return 0;
}
