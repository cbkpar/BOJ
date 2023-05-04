#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long lN;
	cin >> lN;

	long long lLeft = 1;
	long long lRight = 1LL << 62;
	long long lAns = 1LL << 62;

	while (lLeft <= lRight)
	{
		long long lMid = (lLeft + lRight) >> 1;
		long long lTemp = lMid - (lMid / 3) - (lMid / 5) + (lMid / 15);
		if (lTemp < lN)
		{
			lLeft = lMid + 1;
		}
		else
		{
			if (lTemp == lN)
			{
				lAns = min(lAns, lMid);
			}
			lRight = lMid - 1;
		}
	}
	while ((lAns % 3 == 0) || (lAns % 5 == 0)) ++lAns;
	cout << lAns << "\n";
	return 0;
}
