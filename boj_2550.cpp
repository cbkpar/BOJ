#include <iostream>
#include <map>
#include <memory.h>
#include <algorithm>

using namespace std;

int arrNumber[10001] = { 0, };
int arrNumber2[10001] = { 0, };
int arrOrder[10001] = { 0, };
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	arrNumber[0] = -1;

	int iN;
	cin >> iN;

	map<int, int> mapSwitchToNum;
	map<int, int> mapNumToSwitch;

	for (int i = 1; i <= iN; ++i)
	{
		int iNumber;
		cin >> iNumber;
		mapSwitchToNum.emplace(iNumber, i);
		mapNumToSwitch.emplace(i, iNumber);
	}
	int iSize = 1;
	for (int i = 1; i <= iN; ++i)
	{
		int iNumber;
		cin >> arrNumber2[i];
		iNumber = mapSwitchToNum[arrNumber2[i]];
		if (arrNumber[iSize - 1] < iNumber)
		{
			arrOrder[i] = iSize;
			arrNumber[iSize++] = iNumber;
		}
		else
		{
			int iLeft = 0;
			int iRight = iSize - 1;
			while (iLeft < iRight)
			{
				int iMid = (iLeft + iRight) / 2;
				if (arrNumber[iMid] < iNumber)
				{
					iLeft = iMid + 1;
				}
				else
				{
					iRight = iMid;
				}
			}
			arrNumber[iLeft] = iNumber;
			arrOrder[i] = iLeft;
		}
	}
	cout << (iSize - 1) << "\n";
	int* arrAns = new int[iSize];
	memset(arrAns, 0, sizeof(int) * (iSize));
	int iIndex = 0;
	--iSize;
	for (int i = iN; i > 0; --i)
	{
		if (arrOrder[i] == iSize)
		{
			arrAns[iIndex++] = arrNumber2[i];
			--iSize;
		}
	}
	sort(arrAns, arrAns + iIndex);
	for (int i = 0; i < iIndex - 1; ++i)
	{
		cout << arrAns[i] << " ";
	}
	cout << arrAns[iIndex - 1] << "\n";
	delete[] arrAns;
	return 0;
}
