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
	double dMin = 2000000000.0;
	double dMax = 0.0;
	double dSum = 0.0;
	for (int i = 0; i < iN; ++i)
	{
		double dA, dB;
		cin >> dA >> dB;
		dMin = min(dMin, dA / dB);
		dMax = max(dMax, dA / dB);
		dSum += dA / dB;
	}
	cout << fixed;
	cout.precision(20);
	cout << dMin << " ";
	cout << dMax << " ";
	cout << dSum << "\n";
	return 0;
}
