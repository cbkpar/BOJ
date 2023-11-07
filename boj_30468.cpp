#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int iStr, iDex, iInt, iLuk;
	cin >> iStr >> iDex >> iInt >> iLuk;

	int iN;
	cin >> iN;

	int iSum = iStr + iDex + iInt + iLuk;

	if (iSum < iN * 4)
	{
		cout << (iN * 4 - iSum) << "\n";
	}
	else
	{
		cout << "0" << "\n";
	}
	return 0;
}
