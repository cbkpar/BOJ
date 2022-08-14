#include <iostream>
#include <memory.h>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while (true)
	{
		string strNumber;
		cin >> strNumber;
		if ("0" == strNumber)
		{
			break;
		}
		int iSize = strNumber.length();
		int* arrNumber = new int[iSize];
		memset(arrNumber, 0, sizeof(int) * iSize);
		int iLeft = 0;
		int iRight = iSize - 1;
		for (int i = 0; i < iSize; ++i)
		{
			arrNumber[i] = strNumber[i] - '0';
		}
		while (iLeft <= iRight)
		{
			if (arrNumber[iLeft] >= arrNumber[iRight])
			{
				arrNumber[iRight] = arrNumber[iLeft];
			}
			else
			{
				int iMid = iRight - 1;
				++arrNumber[iMid];
				while (arrNumber[iMid] >= 10)
				{
					++arrNumber[iMid - 1];
					arrNumber[iMid] -= 10;
					--iMid;
				}
				arrNumber[iRight] = arrNumber[iLeft];
			}
			++iLeft;
			--iRight;
		}
		int iTempBefore = 0;
		for (int i = 0; i < iSize; ++i)
		{
			iTempBefore *= 10;
			iTempBefore += strNumber[i] - '0';
		}
		int iTempAfter = 0;
		for (int i = 0; i < iSize; ++i)
		{
			iTempAfter *= 10;
			iTempAfter += arrNumber[i];
		}
		delete[] arrNumber;
		cout << (iTempAfter - iTempBefore) << "\n";
	}
	return 0;
}
