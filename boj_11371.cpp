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

	while (true)
	{
		double dX, dY;
		cin >> dX >> dY;

		if (dX == 0 && dY == 0) break;

		double dDeg = atan2f(dY, dX) * 180 / 3.141592f;
		int iAns = round(dDeg);
		cout << iAns << "\n";
	}

	return 0;
}
