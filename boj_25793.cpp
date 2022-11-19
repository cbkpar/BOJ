#include <iostream>

using namespace std;

long long lCalcCount(long long lR, long long lC)
{
	long long lMin = (lR > lC ? lR : lC);
	if (lMin <= 0)
	{
		return 0;
	}
	long long lTemp = lMin * lR * lC;
	lTemp -= ((lMin - 1) * (lMin) / 2) * (lR + lC);
	lTemp += (lMin - 1) * (lMin) * (2 * lMin - 1) / 6;
	return lTemp;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	while (iT--)
	{
		long long lR, lC;
		cin >> lR >> lC;
		long long lAns = lCalcCount(lR, lC) + lCalcCount(lR - 1, lC - 1);
		cout << lAns << " " << (lAns - (lR > lC ? lC : lR)) << "\n";
	}
	return 0;
}
