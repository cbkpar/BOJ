#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;

	int iNow = 1;
	int iAns = 0;

	for (int i = 0;i < iM;++i)
	{
		int iNum;
		cin >> iNum;

		if (iNow >= iNum)
		{
			iAns += min(iNow - iNum, iN - iNow + iNum);
		}
		else
		{
			iAns += min(iNum - iNow, iNow + iN - iNum);
		}
		iNow = iNum;
	}

	cout << iAns << "\n";

	return 0;
}
