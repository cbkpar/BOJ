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

	int iN, iS;
	cin >> iN >> iS;

	int iAns = 0;
	int iNow = iS;
	for (int i = 0; i < iN; ++i)
	{
		string strType;
		cin >> strType;

		int iNeed = strType[0] - '0';
		if (strType.length() == 2)
		{
			++iNeed;
		}

		if (iNeed > iNow)
		{
			iNow = iS;
			++iAns;
		}
		iNow -= iNeed;
	}
	
	cout << iAns << "\n";
	return 0;
}
