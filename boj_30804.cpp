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

	vector<int> vecNum(iN, 0);
	for (int i = 0;i < iN;++i)
	{
		cin >> vecNum[i];
	}

	vector<int> vecCount(10, 0);
	int iNow = 0;

	int iAns = 0;
	int iLeft = 0;
	int iRight = 0;

	while (iRight < iN)
	{
		if (iNow <= 2)
		{
			if (vecCount[vecNum[iRight++]]++ == 0)
			{
				++iNow;
			}
		}
		else
		{
			if (--vecCount[vecNum[iLeft++]] == 0)
			{
				--iNow;
			}
		}
		if (iNow <= 2)
		{
			iAns = max(iAns, iRight - iLeft);
		}
	}

	cout << iAns << "\n";
	return 0;
}
