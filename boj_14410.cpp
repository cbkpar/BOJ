#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	double dSum = 0.0;

	vector<double> vecMoney(iN, 0.0);
	for (int i = 0;i < iN;++i)
	{
		cin >> vecMoney[i];
		dSum += vecMoney[i];
	}

	sort(vecMoney.begin(), vecMoney.end(), greater<double>());

	double dMax = -1000000000.0;
	double dTempSum = 0.0;
	double dAnsA = 0.0;
	double dAnsB = 0.0;

	for (int i = 0;i < iN;++i)
	{
		dTempSum += vecMoney[i];
		double dA = (double)(i + 1) / (double)iN * 100.0;
		double dB = dTempSum / dSum * 100.0;

		if (dB - dA > dMax)
		{
			dAnsA = dA;
			dAnsB = dB;
			dMax = dB - dA;
		}
	}

	cout.precision(20);
	cout << fixed;
	cout << dAnsA << "\n";
	cout << dAnsB << "\n";

	return 0;
}
