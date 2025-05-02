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

	int iT;
	cin >> iT;
	for (int t = 1; t <= iT; ++t)
	{
		int iN;
		cin >> iN;

		vector<int> vecNum(iN, 0);
		for (int i = 0; i < iN; ++i)
		{
			int iFriend;
			cin >> iFriend;
			vecNum[i] = 1 << i;
			for (int j = 0; j < iFriend; ++j)
			{
				int iFriendNum;
				cin >> iFriendNum;
				vecNum[i] |= (1 << (iFriendNum - 1));
			}
		}

		int iAns = iN;
		for (int i = 0; i < (1 << iN); ++i)
		{
			int iTemp = i;
			int iCount = 0;
			int iConnected = 0;
			for (int j = 0; j < iN; ++j)
			{
				if (iTemp % 2 == 1)
				{
					++iCount;
					iConnected |= vecNum[j];
				}
				iTemp /= 2;
			}

			if (iConnected == (1 << iN) - 1)
			{
				iAns = min(iAns, iCount);
			}
		}

		cout << iAns << "\n";
	}
	return 0;
}
