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

	int iNow = 0;
	int iNowIndex = 0;

	for (int i = 0;i < iN;++i)
	{
		int iCount;
		cin >> iCount;

		if (iNow + iCount > iM)
		{
			iNow = iCount;
			++iNowIndex;
		}
		else
		{
			iNow += iCount;
		}
		cout << iNowIndex << "\n";
	}

	return 0;
}
