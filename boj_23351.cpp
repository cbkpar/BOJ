#include <iostream>
#include <memory.h>

using namespace std;

int main()
{
	int iN, iK, iA, iB;
	cin >> iN >> iK >> iA >> iB;
	int* arrWater = new int[iN];
	memset(arrWater, 0, sizeof(int)*iN);
	int iDay = 0;
	int iNumber = 0;
	while (true)
	{
		++iDay;
		for (int i = 0; i < iA; ++i)
		{
			arrWater[(iNumber++) % iN] += iB;
		}
		for (int i = 0; i < iN; ++i)
		{
			if (arrWater[i] + iK <= iDay)
			{
				cout << iDay << "\n";
				delete[] arrWater;
				return 0;
			}
		}
	}
	delete[] arrWater;
	return 0;
}
