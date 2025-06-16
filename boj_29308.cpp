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

	int iN;
	cin >> iN;

	int iAns = -1;
	string strAns = "";

	for (int i = 0;i < iN;++i)
	{
		int iCost;
		cin >> iCost;
		string strName, strCountry;
		cin >> strName >> strCountry;

		if (strCountry == "Russia" && iCost > iAns)
		{
			iAns = iCost;
			strAns = strName;
		}
	}

	cout << strAns << "\n";
	return 0;
}
