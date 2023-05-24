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
		int iN, iL, iR;
		cin >> iN >> iL >> iR;
		if (iN == 0 && iL == 0 && iR == 0) break;

		vector<int> vecNum(iN, 0);
		for (int i = 0; i < iN; ++i) cin >> vecNum[i];

		int iAns = 0;
		for (int i = iL; i <= iR; ++i)
		{
			bool bIsLeap = (iN % 2 == 0 ? true : false);
			for (int j = 0; j < iN; ++j)
			{
				if (j % 2 == 0)
				{
					if (i % vecNum[j] == 0)
					{
						bIsLeap = true;
						break;
					}
				}
				else
				{
					if (i % vecNum[j] == 0)
					{
						bIsLeap = false;
						break;
					}
				}
			}
			if (bIsLeap) ++iAns;
		}
		cout << iAns << "\n";
	}
	return 0;
}
