#include <iostream>
#include <algorithm>

using namespace std;

int mapNumber[1025][1025] = { 0, };

int SelectNumber(int iR, int iC, int iSize)
{
	if (iSize == 1)
	{
		return mapNumber[iR][iC];
	}
	int arrNumber[4] = { 0, };
	arrNumber[0] = SelectNumber(iR, iC, iSize / 2);
	arrNumber[1] = SelectNumber(iR + iSize / 2, iC, iSize / 2);
	arrNumber[2] = SelectNumber(iR, iC + iSize / 2, iSize / 2);
	arrNumber[3] = SelectNumber(iR + iSize / 2, iC + iSize / 2, iSize / 2);
	sort(arrNumber, arrNumber + 4);
	return arrNumber[1];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iSize;
	cin >> iSize;
	for (int i = 0; i < iSize; ++i)
	{
		for (int j = 0; j < iSize; ++j)
		{
			cin >> mapNumber[i][j];
		}
	}
	cout << SelectNumber(0, 0, iSize) << "\n";
	return 0;
}
