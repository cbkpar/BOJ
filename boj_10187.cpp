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

	double dPI = (1.0 + sqrt(5.0)) / 2.0;

	int iN;
	cin >> iN;
	while (iN--)
	{
		double dA, dB;
		cin >> dA >> dB;
		double dRatio = 1.0;
		if (dB != 0)
		{
			dRatio = dA / dB;
		}
		if (dRatio >= dPI * 0.99 && dRatio <= dPI * 1.01)
		{
			cout << "golden" << "\n";
		}
		else
		{
			cout << "not" << "\n";
		}
	}
	return 0;
}
