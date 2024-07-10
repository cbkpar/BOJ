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

	double dN, dT;
	cin >> dN >> dT;

	double dM;
	cin >> dM;

	double dX, dY;
	cin >> dX >> dY;

	double dAns = ((dM / dX) + (dN - dM) / dY) / 60.0 - dT;
	if (dAns < 0.0) dAns = 0.0;

	cout << (int)ceil(dAns) << "\n";
	return 0;
}
