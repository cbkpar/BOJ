#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	long long lK, lM;
	cin >> lK >> lM;

	vector<long long> vecLen(iN, 0);
	for (int i = 0;i < iN;++i)
	{
		cin >> vecLen[i];
	}

	long long lMaxCount = 0;
	long long lAns = -1;

	long long lLeft = 1;
	long long lRight = 1000000001L;

	while (lLeft <= lRight)
	{
		long long lMid = (lLeft + lRight) >> 1;
		long long lCount = 0;
		for (int i = 0;i < iN;++i)
		{
			long long lLen = vecLen[i] - lK;
			if (lLen >= lK) lLen -= lK;
			if (lLen <= 0) continue;
			lCount += (lLen) / lMid;
		}

		if (lCount >= lM)
		{
			lAns = max(lAns, lMid);
			lLeft = lMid + 1;
		}
		else
		{
			lRight = lMid - 1;
		}
	}

	cout << lAns << "\n";
	return 0;
}
