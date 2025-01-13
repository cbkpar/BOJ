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
	while (iT-- > 0)
	{
		int iN;
		cin >> iN;
		vector<int> vecNum(6, 0);
		for (int i = 0;i < 6;++i)
		{
			cin >> vecNum[i];
		}

		int iS = 0;
		int iNow = 0;
		int iIndex = 0;
		while (true)
		{
			if (iNow + vecNum[iIndex % 6] <= iN)
			{
				iNow += vecNum[(iIndex) % 6];
				iS += iNow;
			}
			++iIndex;

			if (iNow == iN) break;
		}
		cout << iS << "\n";
	}

	return 0;
}
