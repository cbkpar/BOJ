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

	int iX, iY, iD, iT;
	cin >> iX >> iY >> iD >> iT;

	double dDist = sqrt(iX * iX + iY * iY);
	if (iD <= iT)
	{
		cout << fixed;
		cout.precision(20);
		cout << dDist << "\n";
	}
	else
	{
		double dAns = dDist;

		int iCount = dDist / iD;
		dAns = min(dAns, (double)(iCount)*iT + (dDist - (double)iCount * iD));
		dAns = min(dAns, (double)(iCount + 1) * iT + ((double)(iCount + 1) * iD) - dDist);
		if (iCount == 0)
		{
			dAns = min(dAns, (double)(iCount + 2) * iT);
		}
		else
		{
			dAns = min(dAns, (double)(iCount + 1) * iT);
		}
		cout << fixed;
		cout.precision(20);
		cout << dAns << "\n";
	}

	return 0;
}
