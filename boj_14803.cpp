#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	for (int t = 1; t <= iT; ++t)
	{
		double dDist;
		int iN;
		cin >> dDist >> iN;

		double dMax = dDist * 100000;
		while (iN--)
		{
			double dTempDist, dSpeed;
			cin >> dTempDist >> dSpeed;

			double dMaxSpeed = (dDist - dTempDist) / dSpeed;
			dMax = min(dMax, dDist / dMaxSpeed);
		}
		cout << fixed;
		cout.precision(60);
		cout << "Case #" << t << ": " << dMax << "\n";
	}

	return 0;
}
