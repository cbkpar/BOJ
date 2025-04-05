#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iD, iK;
	cin >> iN >> iD >> iK;

	int iMax = 0;

	for (int i = 0;i < iN;++i)
	{
		int iNum;
		cin >> iNum;
		iMax = max(iMax, iNum);
	}

	int iCount = 0;
	int iNow = 0;
	for (int i = 0;i < iD;++i)
	{
		if (iNow + iMax > iK)
		{
			++iCount;
			iNow = iMax;
		}
		else
		{
			iNow += iMax;
		}
	}

	cout << iCount << "\n";
	return 0;
}
