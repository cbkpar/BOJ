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

	double dA, dB;
	cin >> dA >> dB;

	double dAns = sqrt(dA * dA + dB * dB);
	cout.precision(30);
	cout << fixed;
	cout << dAns << "\n";

	return 0;
}
