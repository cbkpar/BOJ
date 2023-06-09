#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

long long gcd(long long lA, long long lB)
{
	if (lB % lA == 0) return lA;
	return gcd(lB % lA, lA);
}

long long Sqrt(long long n) {
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

bool PrimeCheck(int iNum)
{
	if (iNum < 2) return false;
	int iSqrt = (int)sqrt(iNum);
	for (int i = 2; i <= iSqrt; ++i)
	{
		if (iNum % i == 0) return false;
	}
	return true;
}

long long LehmanFactor(long long n)
{
	if (n <= 21)
	{
		for (long long i = 2; i < n; ++i)
		{
			if (n % i == 0) return i;
		}
		return n;
	}

	long long cuberoot = (long long)ceil(cbrt(n));
	for (long long i = 2; i < cuberoot; ++i)
	{
		if (n % i == 0) return i;
	}

	for (long long k = 1; k <= cuberoot; ++k)
	{
		double kn = 2 * sqrt(k) * sqrt(n);
		long long max = floor(kn + cbrt(sqrt(n)) / 4 / sqrt(k));
		for (long long i = ceil(kn); i <= max; ++i)
		{
			long long lNum = i * i - 4 * k * n;
			long long sqrt = Sqrt(lNum);
			if (sqrt * sqrt == lNum)
			{
				return gcd(i + sqrt, n);
			}
		}
	}
	return n;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long lN;
	cin >> lN;

	vector<long long> vecAns;
	while (true)
	{
		long long lDivide = LehmanFactor(lN);
		vecAns.push_back(lDivide);
		if (lDivide == lN || lDivide == 1)
		{
			break;
		}
		lN /= lDivide;
	}
	sort(vecAns.begin(), vecAns.end());
	for (long long lNum : vecAns)
	{
		cout << lNum << "\n";
	}
	return 0;
}
