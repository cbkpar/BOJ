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

	double dA;
	cin >> dA;

	dA = sqrt(dA);
	double dAns = sqrt(sqrt(192)) * dA;

	cout << fixed;
	cout.precision(30);
	cout << dAns << "\n";
	return 0;
}
