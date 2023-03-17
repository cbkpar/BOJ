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

	vector<int> vecValue(iN);
	for (int i = 0; i < iN; ++i) cin >> vecValue[i];

	int iMax = 2000000001;
	for (int i = 0; i < iN; ++i)
	{
		int iLeft = i + 1;
		int iRight = iN - 1;
		while (iLeft <= iRight)
		{
			int iMid = (iLeft + iRight) >> 1;
			int iSum = vecValue[i] + vecValue[iMid];
			if (abs(iSum) < abs(iMax))
			{
				iMax = iSum;
			}
			if (iSum <= 0)
			{
				iLeft = iMid + 1;
			}
			else
			{
				iRight = iMid - 1;
			}
		}
	}
	cout << iMax << "\n";
	return 0;
}
