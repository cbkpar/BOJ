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

	double dA, dB, dC;
	cin >> dA >> dB >> dC;

	double dLeft = 0;
	double dRight = dC + 1;
	double dAns = 0;
	for (int t = 0; t < 10000; ++t)
	{
		double dMid = (dLeft + dRight) / 2.0;
		double dPow = dMid * dMid;

		double dSum = dA * dMid + dB * sin(dMid) - dC;
		if (dSum > 0)
		{
			dRight = dMid;
		}
		else if (dSum < 0)
		{
			dLeft = dMid;
		}
		dAns = dMid;
	}
	cout << fixed;
	cout.precision(60);
	cout << dAns << "\n";
	return 0;
}
