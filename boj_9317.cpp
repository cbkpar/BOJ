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

	double dRatio = sqrt(337);

	while (true)
	{
		double dD, dH, dV;
		cin >> dD >> dH >> dV;
		if (dD == 0 && dH == 0 && dV == 0) break;
		printf("Horizontal DPI: %.02lf\n", (dH * dRatio / 16.0 / dD));
		printf("Vertical DPI: %.02lf\n", (dV * dRatio / 9.0 / dD));
	}

	return 0;
}
