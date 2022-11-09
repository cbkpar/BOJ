#include <iostream>

using namespace std;

int arrNumber[1000000] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;
	int iSum = 0;
	int iAns1 = 0;
	int iAns2 = 0;
	int iAverage = 0;
	for (int i = 0; i < iN; ++i)
	{
		cin >> arrNumber[i];
		iSum += arrNumber[i];
	}
	iAverage = iSum / iN;
	for (int i = 0; i < iN; ++i)
	{
		if (arrNumber[i] < iAverage)
		{
			iAns1 += iAverage - arrNumber[i];
		}
		if (arrNumber[i] > iAverage + 1)
		{
			iAns2 += arrNumber[i] - iAverage - 1;
		}
	}
	cout << (iAns1 > iAns2 ? iAns1 : iAns2) << "\n";
	return 0;
}
