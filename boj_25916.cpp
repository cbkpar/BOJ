#include <iostream>
#include <memory.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;
	int* arrNumber = new int[iN];
	memset(arrNumber, 0, sizeof(int) * iN);
	for (int i = 0; i < iN; ++i)
	{
		cin >> arrNumber[i];
	}
	int iLeft = 0;
	int iMax = 0;
	int iNow = 0;
	for (int i = 0; i < iN; ++i)
	{
		iNow += arrNumber[i];
		while (iNow > iM)
		{
			iNow -= arrNumber[iLeft++];
		}
		if (iNow > iMax)
		{
			iMax = iNow;
		}
	}
	cout << iMax << "\n";
	delete[] arrNumber;
	return 0;
}
