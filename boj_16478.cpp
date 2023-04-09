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

	double dD = dA * dC / dB;

	cout << fixed;
	cout.precision(30);
	cout << dD << "\n";
	return 0;
}
