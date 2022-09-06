#include <iostream>

using namespace std;

int main()
{
	int iN;
	cin >> iN;
	int iBefore = -1;
	int iBeforeCost = 0;
	int iCost = 0;
	while (iN--)
	{
		int iNext;
		cin >> iNext;
		if (iBefore == iNext)
		{
			iBeforeCost *= 2;
		}
		else
		{
			iBeforeCost = 2;
		}
		iCost += iBeforeCost;
		iBefore = iNext;
		if (iCost >= 100)
		{
			iCost = 0;
			iBefore = -1;
		}
	}
	cout << iCost << endl;
	return 0;
}
