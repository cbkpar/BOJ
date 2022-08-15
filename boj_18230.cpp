#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int iN, iA, iB;
	cin >> iN >> iA >> iB;
	int* ArrSizeOne = new int[iA];
	int* ArrSizeTwo = new int[iB];
	memset(ArrSizeOne, 0, sizeof(int) * iA);
	memset(ArrSizeTwo, 0, sizeof(int) * iB);
	for (int i = 0; i < iA; ++i)
	{
		cin >> ArrSizeOne[i];
	}
	for (int i = 0; i < iB; ++i)
	{
		cin >> ArrSizeTwo[i];
	}
	sort(ArrSizeOne, ArrSizeOne + iA, greater<int>());
	sort(ArrSizeTwo, ArrSizeTwo + iB, greater<int>());
	int iSum = 0;
	int iIndexOne = 0;
	int iIndexTwo = 0;
	while (iN)
	{
		if (iN >= 2)
		{
			if (iIndexOne + 2 <= iA && iIndexTwo + 1 <= iB)
			{
				if (ArrSizeTwo[iIndexTwo] >= ArrSizeOne[iIndexOne] + ArrSizeOne[iIndexOne + 1])
				{
					iSum += ArrSizeTwo[iIndexTwo++];
					iN -= 2;
				}
				else
				{
					iSum += ArrSizeOne[iIndexOne++];
					--iN;
				}
			}
			else if (iIndexTwo + 1 <= iB)
			{
				iSum += ArrSizeTwo[iIndexTwo++];
				iN -= 2;
			}
			else
			{
				iSum += ArrSizeOne[iIndexOne++];
				--iN;
			}
		}
		else
		{
			iSum += ArrSizeOne[iIndexOne++];
			--iN;
		}
	}
	cout << iSum << "\n";
	delete[] ArrSizeOne;
	delete[] ArrSizeTwo;
	return 0;
}
