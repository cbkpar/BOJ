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
		vector<int> vecNum(iN, 0);
		for (int i = 0; i < iN; ++i) cin >> vecNum[i];
		sort(vecNum.begin(), vecNum.end());

		int iAns = 0;
		for (int k = 1; k < iN - 1; ++k)
		{
			int iLeft = k - 1;
			int iRight = k + 1;
			while (true)
			{
				if (iLeft < 0 || iRight > iN - 1) break;
				int iDiffLeft = vecNum[k] - vecNum[iLeft];
				int iDiffRight = vecNum[iRight] - vecNum[k];

				if (iDiffLeft > iDiffRight)
				{
					++iRight;
				}
				else if (iDiffLeft == iDiffRight)
				{
					++iAns;
					--iLeft;
					++iRight;
				}
				else
				{
					--iLeft;
				}
			}
		}
		cout << iAns << "\n";
	}
	return 0;
}
