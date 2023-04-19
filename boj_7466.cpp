#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

long long sqrt(long long n) {
	if (n <= 1) return n;
	long long lo = 0, hi = n;
	while (lo <= hi) {
		long long mid = (lo + hi) / 2;
		if (mid > n / mid)
		{
			hi = mid - 1;
		}
		else {
			lo = mid + 1;
		}
	}
	return hi;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iR, iC;
	cin >> iR >> iC;

	long long lSumR = 0;
	long long lSumC = 0;

	for (int i = 1; i < iR; ++i)
	{
		long lNum;
		cin >> lNum;
		lSumR += lNum;
	}
	for (int i = 1; i < iC; ++i)
	{
		long lNum;
		cin >> lNum;
		lSumC += lNum;
	}
	long long lSum = lSumR * lSumR + lSumC * lSumC;
	long long lSqrt = sqrt(lSum);
	if (lSqrt * lSqrt != lSum)
	{
		++lSqrt;
	}
	cout << lSqrt << "\n";
	return 0;
}
