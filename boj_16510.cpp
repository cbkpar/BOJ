#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;

	vector<int> vecNum(iN + 2, 0);
	for (int i = 1; i <= iN; ++i)
	{
		cin >> vecNum[i];
		vecNum[i] += vecNum[i - 1];
	}
	vecNum[iN + 1] = 2000000001;
	while (iM--)
	{
		int iNum;
		cin >> iNum;

		int iLeft = 0;
		int iRight = iN + 1;
		while (iLeft < iRight)
		{
			int iMid = (iLeft + iRight) >> 1;
			if (iNum >= vecNum[iMid])
			{
				iLeft = iMid + 1;
			}
			else
			{
				iRight = iMid;
			}
		}
		cout << (iRight - 1) << "\n";
	}
	return 0;
}
