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

	int iMax = -1;
	string strAns = "";

	while (iN--)
	{
		string strName;
		int iCost;
		cin >> strName >> iCost;
		if (iCost > iMax)
		{
			iMax = iCost;
			strAns = strName;
		}
	}
	cout << strAns << "\n";

	return 0;
}
