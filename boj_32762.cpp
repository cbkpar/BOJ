#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;

	for (int i = 0;i < iN;++i)
	{
		int iS, iE;
		cin >> iS >> iE;
	}

	double dSum = 0;

	for (int i = 0;i < iM;++i)
	{
		int iT, iP;
		cin >> iT >> iP;

		dSum += iP;
	}

	cout << fixed;
	cout.precision(30);
	cout << (dSum / iN) << "\n";
	return 0;
}
