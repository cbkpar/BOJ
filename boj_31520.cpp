#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int CalcChampernowne(int iNum)
{
	if (iNum == 1) return 1;
	if (iNum == 12) return 2;
	if (iNum == 123) return 3;
	if (iNum == 1234) return 4;
	if (iNum == 12345) return 5;
	if (iNum == 123456) return 6;
	if (iNum == 1234567) return 7;
	if (iNum == 12345678) return 8;
	if (iNum == 123456789) return 9;
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iNum;
	cin >> iNum;
	cout << CalcChampernowne(iNum) << "\n";
	return 0;
}
