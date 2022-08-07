#include <iostream>
#include <memory.h>

#define Safe_Release_Array(p) if(p){delete[] p;p=nullptr;}

using namespace std;

int main()
{
	int iN, iClass, iRange, iCoupon;
	cin >> iN >> iClass >> iRange >> iCoupon;
	int* pArrFood = new int[iN];
	memset(pArrFood, 0, sizeof(int) * iN);
	int* pArrRef = new int[iClass];
	memset(pArrRef, 0, sizeof(int) * (iClass));
	int iMaxCount = 0;
	int iCount = 1;
	++pArrRef[iCoupon - 1];
	for (int i = 0; i < iN; ++i)
	{
		cin >> pArrFood[i];
		--pArrFood[i];
	}
	for (int i = 0; i < iRange; ++i)
	{
		if (0 == pArrRef[pArrFood[i]]++)
		{
			++iCount;
		}
	}
	for (int i = iRange; i < iRange + iN;++i)
	{
		if (0 == --pArrRef[pArrFood[(i - iRange + iN) % iN]])
		{
			--iCount;
		}
		if (0 == pArrRef[pArrFood[i % iN]]++)
		{
			++iCount;
		}
		iMaxCount = iMaxCount > iCount ? iMaxCount : iCount;
	}
	cout << iMaxCount << endl;
	Safe_Release_Array(pArrRef);
	Safe_Release_Array(pArrFood);
	return 0;
}
