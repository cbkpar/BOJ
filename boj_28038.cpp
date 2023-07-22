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
		int iCase;
		cin >> iCase;
		if (iCase == 1)
		{
			double dX, dY;
			cin >> dX >> dY;

			double dR = sqrt(dX * dX + dY * dY);
			double dTheta = 0.0;
			if (dX != 0.0 || dY != 0.0) dTheta = atan2(dY, dX);
			if (dTheta < 0.0) dTheta += 3.14159265358979 * 2.0;
			
			cout << fixed;
			cout.precision(30);
			cout << dR << " " << dTheta << "\n";
		}
		else
		{
			double dR, dTheta;
			cin >> dR >> dTheta;

			double dX = dR * cos(dTheta);
			double dY = dR * sin(dTheta);

			cout << fixed;
			cout.precision(30);
			cout << dX << " " << dY << "\n";
		}
	}
	return 0;
}
