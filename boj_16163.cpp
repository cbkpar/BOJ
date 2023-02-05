#include <iostream>
#include <string>

using namespace std;

int ArrNum[4000001] = { 0, };
int ArrCount[4000001] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string strWord;
	cin >> strWord;

	int iN = strWord.length();

	for (int i = 0; i < iN; ++i)
	{
		ArrNum[i * 2 + 1] = strWord[i];
	}

	int iP, iR;
	iP = iR = 0;

	for (int i = 0; i < iN * 2 + 1; ++i)
	{
		if (i <= iR) ArrCount[i] = (ArrCount[2 * iP - i] < iR - i ? ArrCount[2 * iP - i] : iR - i);
		while (i - ArrCount[i] - 1 >= 0 && i + ArrCount[i] + 1 < iN * 2 + 1 && ArrNum[i - ArrCount[i] - 1] == ArrNum[i + ArrCount[i] + 1]) ++ArrCount[i];
		if (i + ArrCount[i] > iR) iR = i + ArrCount[i], iP = i;
	}

	long long lCount = 0;
	for (int i = 0; i < iN * 2 + 1; ++i)
	{
		lCount += (ArrCount[i] + 1) / 2;
	}

	cout << lCount << "\n";

	return 0;
}
