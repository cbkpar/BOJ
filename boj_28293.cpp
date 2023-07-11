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

	int iAns = (int)ceil(log10(dA) * dB);
	cout << iAns << "\n";
	return 0;
}
