#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iA, iB, iC;
	cin >> iA >> iB >> iC;
	int iCount = 0;
	iCount += iA / 3;
	iCount += iB / 3;
	iCount += iC / 3;
	iA %= 3;
	iB %= 3;
	iC %= 3;
	int iMax = 0;
	int iZero = 3;
	if (iA > iMax) iMax = iA;
	if (iB > iMax) iMax = iB;
	if (iC > iMax) iMax = iC;
	if (iA == 0) --iZero;
	if (iB == 0) --iZero;
	if (iC == 0) --iZero;
	cout << (iCount + (iMax < iZero ? iMax : iZero)) << "\n";
	return 0;
}
