#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long sqrt(long long n) {
	if (n == 0) return 0;
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

	long long lA, lB, lC, lD;
	cin >> lA >> lB >> lC >> lD;

	long long lSum = 0;
	lSum += min(lA, lB);
	lSum += min(lC, lD);

	cout << sqrt(lSum) << "\n";

	return 0;
}
