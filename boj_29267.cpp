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

	int iSave = 0;
	int iNow = 0;

	string strCommand;
	while (iN--)
	{
		cin >> strCommand;
		if (strCommand == "save")
		{
			iSave = iNow;
		}
		if (strCommand == "load")
		{
			iNow = iSave;
		}
		if (strCommand == "shoot")
		{
			--iNow;
		}
		if (strCommand == "ammo")
		{
			iNow += iK;
		}
		cout << iNow << "\n";
	}

	return 0;
}
