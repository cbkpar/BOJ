#include <iostream>

using namespace std;

int main()
{
	int iM, iK;
	int iSum = 0;
	cin >> iM;
	if (1 == iM)
	{
		cout << "1.0" << endl;
		return 0;
	}
	int* iArr = new int[iM];
	for (int i = 0; i < iM; ++i)
	{
		cin >> iArr[i];
		iSum += iArr[i];
	}
	cin >> iK;
	double dNumerator = 0;
	double dDenominator = 1;
	for (int i = 0; i < iK; ++i)
	{
		dDenominator *= (iSum - i);
	}
	for (int i = 0; i < iM; ++i)
	{
		if (iArr[i] >= iK)
		{
			double dTemp = 1.0f;
			for (int j = 1; j <= iK; ++j)
			{
				dTemp *= iArr[i] - j + 1;
			}
			dNumerator += dTemp;
		}
	}
	cout << fixed;
	cout.precision(12);
	cout << dNumerator / dDenominator << endl;
	return 0;
}
