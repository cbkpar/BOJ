#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long lK;
	long long lA, lX;
	long long lB, lY;
	cin >> lK >> lA >> lX >> lB >> lY;

	long long lAns = 0;
	lAns = max(lAns, max((long long)0, (lK - lA)) * lX + max((long long)0, (lK - lA - lB)) * lY);
	lAns = max(lAns, max((long long)0, (lK - lA - lB)) * lX + max((long long)0, (lK - lB)) * lY);

	cout << lAns << "\n";
	return 0;
}
