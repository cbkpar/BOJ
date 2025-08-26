#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long lTarget;
	cin >> lTarget;

	int iN;
	cin >> iN;

	vector<long long> vecAmount(iN, 0);
	for (int i = 0;i < iN;++i)
	{
		cin >> vecAmount[i];
	}

	long long lAns = 222222222222222LL;
	
	for (int i = 0;i < (1 << iN);++i)
	{
		int iTemp = i;
		long long lSum = 0;
		for (int j = 0;j < iN;++j)
		{
			if ((iTemp & 1) == 1)
			{
				lSum += vecAmount[j];
			}
			iTemp >>= 1;
		}

		if (lSum >= lTarget)
		{
			lAns = min(lAns, lSum);
		}
	}

	if (lAns == 222222222222222LL)
	{
		cout << "IMPOSSIBLE" << "\n";
	}
	else
	{
		cout << lAns << "\n";
	}

	return 0;
}
