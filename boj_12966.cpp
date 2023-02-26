#include <iostream>
#include <vector>
#include <algorithm>

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

	long long lX, lY;
	cin >> lX >> lY;

	long long lSum = lX + lY;
	long long lSqrt = sqrt(lSum);

	if (lSqrt * lSqrt != lSum || lX == 2 || lY == 2)
	{
		cout << "-1\n";
		return 0;
	}

	int iCount = 0;
	for (long long i = lSqrt; i >= 2; --i)
	{
		if (lX >= 2 * i - 1)
		{
			lX -= 2 * i - 1;
			++iCount;
		}
	}
	iCount += lX;
	cout << iCount << "\n";
	return 0;
}
