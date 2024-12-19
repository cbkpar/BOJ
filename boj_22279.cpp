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

	int iN;
	cin >> iN;

	double dSum = 0.0;

	for (int i = 0;i < iN;++i)
	{
		double dA, dB;
		cin >> dA >> dB;
		
		dSum += dA * dB;
	}

	cout << fixed;
	cout.precision(30);
	cout << dSum << "\n";
	return 0;
}
