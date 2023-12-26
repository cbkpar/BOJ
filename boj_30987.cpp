#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long lX1, lX2;
	cin >> lX1 >> lX2;

	long long lA, lB, lC, lD, lE;
	cin >> lA >> lB >> lC >> lD >> lE;

	lB -= lD;
	lC -= lE;

	lA /= 3;
	lB /= 2;

	long long lAns = 0;
	lAns += lA * (lX2 * lX2 * lX2 - lX1 * lX1 * lX1);
	lAns += lB * (lX2 * lX2 - lX1 * lX1);
	lAns += lC * (lX2 - lX1);

	cout << lAns << "\n";
	return 0;
}
