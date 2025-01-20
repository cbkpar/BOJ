#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	long long lR, lK, lM;
	cin >> lR >> lK >> lM;

	long long lPow = 1;

	while (lK <= lM)
	{
		lM -= lK;
		lPow *= 2;
		if (lPow > lR) break;
	}
	lR /= lPow;

	cout << lR << "\n";
	return 0;
}
