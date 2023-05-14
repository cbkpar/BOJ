#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long lTotal = 0;
	string strCost;
	while (cin >> strCost)
	{
		long long lTemp = 0;
		int iSize = strCost.length();
		for (int i = 0; i < iSize; ++i)
		{
			if (strCost[i] == '.') continue;
			lTemp *= 10;
			lTemp += strCost[i] - '0';
		}
		lTotal += lTemp;
	}
	printf("%lld.%02lld\n", lTotal / 100, lTotal % 100);
	return 0;
}
