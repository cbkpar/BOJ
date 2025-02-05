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

	dA /= 3.14159265358979;
	dA = sqrt(dA);
	dA += 1.0;
	dA *= 2;
	dA = dA * dA;

	cout.precision(30);
	cout << fixed;
	cout << dA << "\n";

	return 0;
}
