#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;
	double dRatio = 0.0;
	for (int i = 0; i < iN; ++i)
	{
		double dGauge;
		cin >> dGauge;
		dGauge /= 100.0;
		dRatio = 1 - (1 - dRatio) * (1 - dGauge);
		cout << fixed;
		cout.precision(100);
		cout << (dRatio * 100.0) << "\n";
	}
	return 0;
}
