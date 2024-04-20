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
		int iN, iM;
		cin >> iN >> iM;
		if (iN == 0 && iM == 0) break;

		vector<int> vecNum(iN, 0);
		for (int i = 0; i < iN; ++i) cin >> vecNum[i];

		int iCount = 0;
		while (iM--)
		{
			bool bPossible = true;
			for (int i = 0; i < iN; ++i)
			{
				int iSize;
				cin >> iSize;
				if (iSize > vecNum[i])
				{
					bPossible = false;
				}
			}
			if (bPossible)
			{
				++iCount;
			}
		}
		cout << iCount << "\n";
	}
	return 0;
}
