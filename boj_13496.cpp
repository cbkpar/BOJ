#include <iostream>

using namespace std;

int main()
{
	int iT;
	cin >> iT;
	for (int i = 1; i <= iT; ++i)
	{
		int iN, iSpeed, iDay;
		cin >> iN >> iSpeed >> iDay;
		int iSumMoney = 0;
		while (iN--)
		{
			int iDistance, iMoney;
			cin >> iDistance >> iMoney;
			if (iDistance <= iSpeed * iDay)
			{
				iSumMoney += iMoney;
			}
		}
		if (i != 1)
		{
			cout << endl;
		}
		cout << "Data Set " << i << ":\n" << iSumMoney << endl;
	}
}
