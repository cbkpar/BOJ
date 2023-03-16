#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long gcd(long long lA, long long lB)
{
	if (lB % lA == 0) return lA;
	return gcd(lB % lA, lA);
}

long long Count(long long lN, long long lX, long long lY)
{
	if (lN < lX + lY) return 0;
	long long lAns = 0;
	long long lGCD = (lX < lY ? gcd(lX, lY) : gcd(lY, lX));
	for (long long i = 1; i <= lX / lGCD; ++i)
	{
		if (lN - lY * i < 0) break;
		lAns += (lN - lY * i) / lX;
	}
	return lAns;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long lLeft, lRight, lK;
	cin >> lLeft >> lRight >> lK;

	long long lX, lD;
	lX = lK;
	lD = lK * (lK - 1) / 2;

	cout << (Count(lRight, lX, lD) - Count(lLeft - 1, lX, lD)) << "\n";
	return 0;
}
