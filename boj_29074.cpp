#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long lN, lM;
	cin >> lN >> lM;

	long long lPow = 1;

	while (lPow <= lN)
	{
		lPow *= 10;
	}

	long long lA = lM / lPow;
	long long lB = lM % lPow;

	long long lAns = lA + (lB >= lN ? 1 : 0);

	cout << lAns << "\n";
	return 0;
}
