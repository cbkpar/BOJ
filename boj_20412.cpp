#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long Pow(long long lNum, long long lPow, long long lMod)
{
	long long lAns = 1;
	long long lTemp = lNum;
	while (lPow)
	{
		if (lPow & 1)
		{
			lAns = (lAns * lTemp) % lMod;
		}
		lTemp = (lTemp * lTemp) % lMod;
		lPow /= 2;
	}
	return lAns;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long lM, lSeed, lX1, lX2;
	cin >> lM >> lSeed >> lX1 >> lX2;

	long long lA = (((lX2 - lX1 + lM) % lM) * Pow((lX1 - lSeed + lM) % lM, lM - 2, lM)) % lM;
	long long lC = (((lX1 - lA * lSeed) % lM) + lM) % lM;

	cout << lA << " " << lC << "\n";
}
