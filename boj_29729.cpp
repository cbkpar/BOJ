#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int iS, iN, iM;
	cin >> iS >> iN >> iM;

	int iNow = 0;
	for (int i = 0;i < iN + iM;++i)
	{
		int iCommand;
		cin >> iCommand;

		if (iCommand == 0)
		{
			--iNow;
		}
		else
		{
			if (iNow == iS)
			{
				iS <<= 1;
			}
			++iNow;
		}
	}

	cout << iS << "\n";
	return 0;
}
