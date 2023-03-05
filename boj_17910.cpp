#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long gcd(long long lA, long long lB)
{
	if (lB % lA == 0) return lA;
	return gcd(lB % lA, lA);
}

int main()
{
	int iN;
	cin >> iN;
	vector<long long> vecNum(iN);
	for (int i = 0; i < iN; ++i) cin >> vecNum[i];
	long long lNumerator = vecNum[iN - 1];
	long long lDenometer = 1;

	for (int i = iN - 2; i >= 0; --i)
	{
		long long lNewDeno = lNumerator;
		long long lNewNeme = lDenometer + lNumerator * vecNum[i];
		long long lGCD = (lNewDeno < lNewNeme ? gcd(lNewDeno, lNewNeme) : gcd(lNewNeme, lNewDeno));
		lNumerator = lNewNeme / lGCD;
		lDenometer = lNewDeno / lGCD;
	}
	cout << lNumerator << "/" << lDenometer << "\n";
	return 0;
}
