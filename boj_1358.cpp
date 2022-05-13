#include <iostream>

using namespace std;

int main()
{
	int iW, iH, iX, iY, iP;
	cin >> iW >> iH >> iX >> iY >> iP;
	int iCount = 0;
	for (int i = 0; i < iP; ++i)
	{
		int iPlayerX, iPlayerY;
		cin >> iPlayerX >> iPlayerY;
		if (iPlayerX >= iX && iPlayerX <= iX + iW && iPlayerY >= iY && iPlayerY <= iY + iH) {
			++iCount;
			continue;
		}
		if ((iX - iPlayerX)*(iX - iPlayerX) * 4 + (iY * 2 + iH - iPlayerY * 2)*(iY * 2 + iH - iPlayerY * 2) <= iH*iH) {
			++iCount;
			continue;
		}

		if ((iX + iW - iPlayerX)*(iX + iW - iPlayerX) * 4 + (iY * 2 + iH - iPlayerY * 2)*(iY * 2 + iH - iPlayerY * 2) <= iH*iH) {
			++iCount;
			continue;
		}
	}
	cout << iCount << endl;
	return 0;
}
