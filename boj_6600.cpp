#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	double dX1, dY1, dX2, dY2, dX3, dY3;
	while (cin >> dX1 >> dY1 >> dX2 >> dY2 >> dX3 >> dY3)
	{
		double dA = dX2 - dX1;
		double dB = dY2 - dY1;
		double dC = dX3 - dX2;
		double dD = dY3 - dY2;

		double dP = dX1 * dX1 - dX2 * dX2 + dY1 * dY1 - dY2 * dY2;
		double dQ = dX2 * dX2 - dX3 * dX3 + dY2 * dY2 - dY3 * dY3;

		double dE = dA * dD - dB * dC;

		double dX = (dD * dP - dB * dQ) / dE * (-0.5);
		double dY = (-dC * dP + dA * dQ) / dE * (-0.5);

		double dR = sqrt((dX1 - dX) * (dX1 - dX) + (dY1 - dY) * (dY1 - dY));
		printf("%.2f\n", dR * 2 * 3.141592653589793);
	}
	return 0;
}
