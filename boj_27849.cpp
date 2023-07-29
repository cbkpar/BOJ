#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	long long lT;
	cin >> iN >> lT;

	long long lAns = 0;
	long long lNow = 0;
	long long lAcc = 0;

	while (iN--)
	{
		long long lD, lB;
		cin >> lD >> lB;

		if (lD > lT) break;

		if (lAcc >= lD - 1 - lNow)
		{
			lAns += lD - 1 - lNow;
			lAcc -= lD - 1 - lNow;
		}
		else
		{
			lAns += lAcc;
			lAcc = 0;
		}
		lNow = lD - 1;
		lAcc += lB;
	}

	lAns += min(lAcc, lT-lNow);
	cout << lAns << "\n";
	return 0;
}
