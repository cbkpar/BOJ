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

	long long lA, lPA, lB, lPB;
	cin >> lA >> lPA >> lB >> lPB;

	long long lMax = -1;
	long long lCountA = 0;
	long long lCountB = 0;

	long long lCountMax = lN / lPA;
	for (long long i = 0; i <= lCountMax; ++i)
	{
		long long lPower = i * lA + (lN - i * lPA) / lPB * lB;
		if (lPower > lMax)
		{
			lMax = lPower;
			lCountA = i;
			lCountB = (lN - i * lPA) / lPB;
		}
	}
	cout << lCountA << " " << lCountB << "\n";
	return 0;
}
