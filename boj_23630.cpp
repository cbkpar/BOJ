#include <iostream>

using namespace std;

int main()
{
	int iN;
	int ArrBit[20] = {};
	cin >> iN;
	while (iN--)
	{
		int iNumber;
		cin >> iNumber;
		int iIndex = 0;
		while (iNumber)
		{
			if (iNumber % 2 == 1)
			{
				++ArrBit[iIndex];
			}
			iNumber /= 2;
			++iIndex;
		}
	}
	int iMax = 0;
	for (int i = 0; i < 20; ++i)
	{
		if (ArrBit[i] > iMax) {
			iMax = ArrBit[i];
		}
	}
	cout << iMax << endl;
	return 0;
}
