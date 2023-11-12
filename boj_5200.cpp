#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	for (int t = 1; t <= iT; ++t)
	{
		double dW, dH, dM, dD;
		int iN;
		cin >> dW >> dH >> dM >> dD;
		cin >> iN;

		double dAreaIn = (dW - dM * 2) * (dH - dM * 2);
		double dAreaOut = dW * dH - dAreaIn;
		double dHeight = (dAreaOut * dD) / (dW * dH);

		while (iN--)
		{
			double dH2, dR;
			cin >> dH2 >> dR;

			double dA = dR * dR * 3.141592 * dH2;
			dHeight -= dA / (dW * dH);
		}
		printf("Data Set %d:\n", t);
		printf("%.2f\n", dHeight);
	}
	return 0;
}
