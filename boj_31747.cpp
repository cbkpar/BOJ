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

	int iN, iK;
	cin >> iN >> iK;

	vector<int> vecNum(iN, 0);
	for (int i = 0; i < iN; ++i)
	{
		cin >> vecNum[i];
	}

	int iNow = 0;
	int iFirst = 0;
	int iSecond = 0;

	int iDay = 0;
	while (true)
	{
		while (iFirst + iSecond < iK)
		{
			if (iNow < iN)
			{
				if (vecNum[iNow] == 1)
				{
					++iFirst;
				}
				else if (vecNum[iNow] == 2)
				{
					++iSecond;
				}
				++iNow;
			}
			else
			{
				break;
			}
		}
		++iDay;

		if (iFirst > 0) --iFirst;
		if (iSecond > 0) --iSecond;

		if (iNow == iN && iFirst == 0 && iSecond == 0)
		{
			break;
		}
	}

	cout << iDay << "\n";
	return 0;
}
