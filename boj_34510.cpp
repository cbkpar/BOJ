#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long lA, lB, lC;
	cin >> lA >> lB >> lC;

	long long lH;
	cin >> lH;

	long long lAns = 0;
	if (lH % 2 == 0)
	{
		lAns = (lH / 2) * (lB + lC * 2);
	}
	else
	{
		lAns = (lH / 2) * (lB + lC * 2) + (lA + lB + lC);
	}

	cout << lAns << "\n";
	return 0;
}
