#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;
	double dSum = 0;
	for (int i = 0; i < iN; ++i)
	{
		double dNumber;
		cin >> dNumber;
		dSum += (dNumber * dNumber * dNumber);
	}
	cout << fixed;
	cout.precision(24);
	cout << cbrt(dSum) << "\n";
	return 0;
}
