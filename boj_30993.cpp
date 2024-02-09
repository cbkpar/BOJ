#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long Comb(long long lN, long long lM)
{
	long long lRet = 1;
	for (long long i = 1; i <= lM; ++i)
	{
		lRet *= lN - i + 1;
	}
	for (long long i = 1; i <= lM; ++i)
	{
		lRet /= i;
	}
	return lRet;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	long long lN, lA, lB, lC;
	cin >> lN >> lA >> lB >> lC;

	long long lAns = Comb(lN,lA) * Comb(lN-lA,lB);

	cout << lAns << "\n";
	return 0;
}
