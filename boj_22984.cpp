#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	vector<double> vecPercent(iN);
	for (int i = 0;i < iN;++i) cin >> vecPercent[i];

	double dAns = 0.0;
	for (double dPercent : vecPercent) dAns += dPercent;
	for (int i = 0;i < iN - 1;++i)
	{
		dAns += vecPercent[i] * (1.0 - vecPercent[i + 1]);
		dAns += vecPercent[i + 1] * (1.0 - vecPercent[i]);
	}

	cout << fixed;
	cout.precision(24);
	cout << dAns << "\n";

	return 0;
}
