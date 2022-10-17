#include <iostream>
#include <memory.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM, iL, iK;
	cin >> iN >> iM >> iL >> iK;

	int iMax = 0;
	int* arrX = new int[iK];
	memset(arrX, 0, sizeof(int) * iK);
	int* arrY = new int[iK];
	memset(arrY, 0, sizeof(int) * iK);

	for (int i = 0; i < iK; ++i)
	{
		cin >> arrX[i] >> arrY[i];
	}
	for (int i = 0; i < iK; ++i)
	{
		for (int j = 0; j < iK; ++j)
		{
			int iCount = 0;
			for (int k = 0; k < iK; ++k)
			{
				if (arrX[k] >= arrX[i] && arrX[k] <= arrX[i] + iL && arrY[k] >= arrY[j] && arrY[k] <= arrY[j] + iL)
				{
					++iCount;
				}
			}
			if (iCount > iMax)
			{
				iMax = iCount;
			}
		}
	}
	cout << (iK - iMax) << "\n";
	return 0;
}
