#include <iostream>
#include <memory.h>
#include <algorithm>

using namespace std;

int arrMoney[2000] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;

	for (int i = 0; i < iN; ++i)
	{
		cin >> arrMoney[i];
	}
	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iN + iM; ++j)
		{
			int iMoney;
			cin >> iMoney;
			arrMoney[i] -= iMoney;
			arrMoney[j] += iMoney;
		}
	}
	for (int i = 0; i < iN + iM; ++i)
	{
		cout << arrMoney[i];
		if (i == iN + iM - 1)
		{
			cout << "\n";
		}
		else
		{
			cout << " ";
		}
	}
	return 0;
}
