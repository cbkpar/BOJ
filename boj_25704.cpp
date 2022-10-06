#include <iostream>

using namespace std;

int main()
{
	int iN, iCost;
	cin >> iN >> iCost;
	int iMaxCost = iCost;
	if (iN >= 5)
	{
		if (iMaxCost > iCost - 500)
		{
			iMaxCost = iCost - 500;
		}
	}
	if (iN >= 10)
	{
		if (iMaxCost > iCost * 9 / 10)
		{
			iMaxCost = iCost * 9 / 10;
		}
	}
	if (iN >= 15)
	{
		if (iMaxCost > iCost - 2000)
		{
			iMaxCost = iCost - 2000;
		}
	}
	if (iN >= 20)
	{
		if (iMaxCost > iCost * 3 / 4)
		{
			iMaxCost = iCost * 3 / 4;
		}
	}
	if (iMaxCost < 0)
	{
		iMaxCost = 0;
	}
	cout << iMaxCost << "\n";
	return 0;
}
