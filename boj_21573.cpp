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

	int iRoom, iCond;
	cin >> iRoom >> iCond;

	string strCommand;
	cin >> strCommand;

	if (strCommand == "freeze")
	{
		if (iRoom > iCond) iRoom = iCond;
		cout << iRoom << "\n";
	}

	if (strCommand == "heat")
	{
		if (iRoom < iCond) iRoom = iCond;
		cout << iRoom << "\n";
	}

	if (strCommand == "auto")
	{
		cout << iCond << "\n";
	}

	if (strCommand == "fan")
	{
		cout << iRoom << "\n";
	}
	return 0;
}
