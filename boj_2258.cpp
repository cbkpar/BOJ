#include <iostream>
#include <algorithm>

using namespace std;

struct tMeat
{
	int iWeight;
	int iCost;
};

int main()
{
	int iN;
	cin >> iN;
	int iM;
	cin >> iM;

	tMeat* arrMeat = new tMeat[iN];
	for (int i = 0; i < iN; ++i)
	{
		int iWeight;
		int iCost;
		cin >> iWeight >> iCost;
		arrMeat[i] = { iWeight, iCost };
	}
	sort(arrMeat, arrMeat + iN, [](tMeat &o1, tMeat &o2)
	{
		if (o1.iCost == o2.iCost)
		{
			return o1.iWeight > o2.iWeight;
		}
		else
		{
			return o1.iCost < o2.iCost;
		}
	});
	int iCost = 2147483647;
	int iAccCost = 0;
	int iAccWeight = 0;
	for (int i = 0; i < iN; ++i)
	{
		iAccWeight += (arrMeat + i)->iWeight;
		if (i != 0 && (arrMeat + i)->iCost == (arrMeat + i - 1)->iCost)
		{
			iAccCost += (arrMeat + i)->iCost;
		}
		else
		{
			iAccCost = (arrMeat + i)->iCost;
		}
		if (iAccWeight >= iM && iCost > iAccCost)
		{
			iCost = iAccCost;
		}
	}
	if (iAccWeight >= iM)
	{
		cout << iCost << endl;
	}
	else
	{
		cout << "-1" << endl;
	}
	delete[] arrMeat;
	return 0;
}
