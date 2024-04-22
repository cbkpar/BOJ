#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iA;
	cin >> iA;

	int iN, iM;
	cin >> iN >> iM;

	if (iN > iM) swap(iN, iM);

	double dAns = 0;
	if (iN * 2 < iM * iA)
	{
		dAns = (double)(iN * 2) / iA;
	}
	else
	{
		dAns = iM;
	}

	cout << fixed;
	cout.precision(20);
	cout << dAns << "\n";
	return 0;
}
