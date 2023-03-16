#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	vector<int> vecCount(1000001, 0);
	vector<int> vecNum(iN);
	for (int i = 0; i < iN; ++i)
	{
		int iNum;
		cin >> iNum;
		vecNum[i] = iNum;
		++vecCount[iNum];
	}
	for (int iNum : vecNum)
	{
		if (iNum == 1)
		{
			cout << (vecCount[1] - 1) << "\n";
		}
		else
		{
			int iSqrt = (int)sqrt(iNum);
			int iCount = -1;
			for (int i = 1; i <= iSqrt; ++i)
			{
				if (iNum % i == 0)
				{
					if (i * i == iNum)
					{
						iCount += vecCount[i];
					}
					else
					{
						iCount += vecCount[i] + vecCount[iNum / i];
					}

				}
			}
			cout << iCount << "\n";
		}
	}

	return 0;
}
