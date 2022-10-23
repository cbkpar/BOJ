#include <iostream>
#include <memory.h>
#include <algorithm>

using namespace std;

struct tagPOS
{
	int iS, iE;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	tagPOS* arrPos = new tagPOS[iN];
	memset(arrPos, 0, sizeof(tagPOS) * iN);

	int* arrNumber = new int[iN + 1];
	memset(arrNumber, 0, sizeof(int) * (iN + 1));
	arrNumber[0] = 2147483647;

	for (int i = 0; i < iN; ++i)
	{
		int iNumber;
		cin >> iNumber >> arrPos[i].iS >> arrPos[i].iE;
	}
	sort(arrPos, arrPos + iN, [](tagPOS o1, tagPOS o2)->bool {
		if (o1.iS == o2.iS)
		{
			return o1.iE > o2.iE;
		}
		else
		{
			return o1.iS < o2.iS;
		}
		});

	int iSize = 1;
	int iBeforeS = -1;
	int iBeforeE = -1;
	for (int i = 0; i < iN; ++i)
	{
		if (iBeforeS == arrPos[i].iS && iBeforeE == arrPos[i].iE)
		{
			continue;
		}
		else
		{
			iBeforeS = arrPos[i].iS;
			iBeforeE = arrPos[i].iE;
		}
		int iNumber = arrPos[i].iE;
		if (arrNumber[iSize - 1] >= iNumber)
		{
			arrNumber[iSize++] = iNumber;
		}
		else
		{
			int iLeft = 0;
			int iRight = iSize - 1;
			while (iLeft < iRight)
			{
				int iMid = (iLeft + iRight) / 2;
				if (arrNumber[iMid] >= iNumber)
				{
					iLeft = iMid + 1;
				}
				else
				{
					iRight = iMid;
				}
			}
			arrNumber[iLeft] = iNumber;
		}
	}
	cout << (iSize - 1) << "\n";
	delete[] arrPos;
	delete[] arrNumber;
	return 0;
}
