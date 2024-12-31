#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	double dA, dB;
	cin >> dA >> dB;

	double dAns = (100 / (100 - dB) - 1) * 100.0;

	cout.precision(30);
	cout << fixed;
	cout << dAns << "\n";

	return 0;
}
