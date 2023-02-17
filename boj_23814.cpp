#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long lD;
	cin >> lD;
	long long lN, lM, lK;
	cin >> lN >> lM >> lK;

	long long lAns = lK;
	lN %= lD;
	lM %= lD;

	long long lMax = lK / lD;
	if (lN != 0)
	{
		long long lTemp = lK - (lD - lN);
		if (lTemp >= 0)
		{
			long long lCount = lTemp / lD + 1;
			if (lCount > lMax)
			{
				lAns = lTemp;
				lMax = lCount;
			}
			else if (lCount == lMax)
			{
				if (lTemp > lAns)
				{
					lAns = lTemp;
				}
			}
		}
	}
	if (lM != 0)
	{
		long long lTemp = lK - (lD - lM);
		if (lTemp >= 0)
		{
			long long lCount = lTemp / lD + 1;
			if (lCount > lMax)
			{
				lAns = lTemp;
				lMax = lCount;
			}
			else if (lCount == lMax)
			{
				if (lTemp > lAns)
				{
					lAns = lTemp;
				}
			}
		}
	}

	if (lN != 0 && lM != 0)
	{
		long long lTemp = lK - (lD - lN) - (lD - lM);
		if (lTemp >= 0)
		{
			long long lCount = lTemp / lD + 2;
			if (lCount > lMax)
			{
				lAns = lTemp;
				lMax = lCount;
			}
			else if (lCount == lMax)
			{
				if (lTemp > lAns)
				{
					lAns = lTemp;
				}
			}
		}
	}

	cout << lAns << "\n";
	return 0;
}
