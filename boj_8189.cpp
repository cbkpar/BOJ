#include <iostream>
#include <string>

using namespace std;

int ArrNum[1000001] = { 0, };
int ArrCount[1000001] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	string strWord;
	cin >> strWord;

	for (int i = 0; i < 2 * iN + 1; ++i)
	{
		ArrNum[i] = i + 2;
	}
	for (int i = 0; i < iN; ++i)
	{
		ArrNum[i * 2 + 1] = strWord[i];
	}

	int iP, iR;
	iP = iR = -1;

	for (int i = 0; i < iN * 2 + 1; i+=2)
	{
		if (i <= iR) ArrCount[i] = (ArrCount[2 * iP - i] < iR - i ? ArrCount[2 * iP - i] : iR - i);
		while (i - ArrCount[i] - 1 >= 0 && i + ArrCount[i] + 1 < iN * 2 + 1 && ArrNum[i - ArrCount[i] - 1] != ArrNum[i + ArrCount[i] + 1]) ++ArrCount[i];
		if (i + ArrCount[i] > iR) iR = i + ArrCount[i], iP = i;
	}

	long lSum = 0;

	for (int i = 0; i < iN * 2 + 1; i += 2)
	{
		lSum += ArrCount[i] / 2;
	}

	cout << lSum << "\n";

	return 0;
}
