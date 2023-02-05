#include <iostream>

using namespace std;

int ArrNum[2000001] = { 0, };
int ArrCount[2000001] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	for (int i = 0; i < iN; ++i)
	{
		cin >> ArrNum[i * 2 + 1];
	}

	int iP, iR;
	iP = iR = 0;

	for (int i = 0; i < iN * 2 + 1; ++i)
	{
		if (i <= iR) ArrCount[i] = (ArrCount[2 * iP - i] < iR - i ? ArrCount[2 * iP - i] : iR - i);
		while (i - ArrCount[i] - 1 >= 0 && i + ArrCount[i] + 1 < iN * 2 + 1 && ArrNum[i - ArrCount[i] - 1] == ArrNum[i + ArrCount[i] + 1]) ++ArrCount[i];
		if (i + ArrCount[i] > iR) iR = i + ArrCount[i], iP = i;
	}

	int iQuery;
	cin >> iQuery;
	while (iQuery--)
	{
		int iS, iE;
		cin >> iS >> iE;
		int iNum = iS + iE - 1;
		if (ArrCount[iNum] >= iE - iS + 1)
		{
			cout << "1\n";
		}
		else
		{
			cout << "0\n";
		}
	}

	return 0;
}
