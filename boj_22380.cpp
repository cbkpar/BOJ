#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true)
	{
		int iN, iM;
		cin >> iN >> iM;
		if (iN == 0 && iM == 0) break;

		int iSum = 0;
		int iCost = iM / iN;
		for (int i = 0; i < iN; ++i)
		{
			int iMoney;
			cin >> iMoney;
			if (iMoney > iCost) iMoney = iCost;
			iSum += iMoney;
		}
		cout << iSum << "\n";
	}
	return 0;
}
