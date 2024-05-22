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

	int iT;
	cin >> iT;
	while (iT--)
	{
		int iN;
		cin >> iN;

		double dAns = 0;
		while (iN--)
		{
			double dX1, dY1, dX2, dY2;
			cin >> dX1 >> dY1 >> dX2 >> dY2;

			double dAngle1 = atan2(dX1, dY1) / 3.1415926535;
			double dAngle2 = atan2(dX2, dY2) / 3.1415926535;

			double dCalc = abs((dAngle1 - dAngle2)) / 2.0;
			if (dCalc > 0.5) dCalc = 1 - dCalc;
			dAns += dCalc;
		}
		cout.precision(5);
		cout << fixed;
		cout << dAns << "\n";
	}

	return 0;
}
