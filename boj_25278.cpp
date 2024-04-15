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

	int iTemp = -30;
	int iOxygen = 0;
	int iOcean = 0;

	int iN;
	cin >> iN;
	while (iN--)
	{
		string strType, strAmount;
		cin >> strType >> strAmount;
		if (strType == "temperature") iTemp += strAmount[1] - '0';
		if (strType == "oxygen") iOxygen += strAmount[1] - '0';
		if (strType == "ocean") iOcean += strAmount[1] - '0';
	}

	if (iTemp >= 8 && iOxygen >= 14 && iOcean >= 9)
	{
		cout << "liveable" << "\n";
	}
	else
	{
		cout << "not liveable" << "\n";
	}
	
	return 0;
}
