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

	int iT;
	cin >> iT;
	while (iT--)
	{
		long long lN;
		cin >> lN;

		long long lSum = lN * (lN + 1) / 2;
		long long lTemp = sqrt(lSum * 4 + 1);
		long long lAns = (lTemp + 1) / 2;
		cout << lAns << "\n";
	}
	return 0;
}
