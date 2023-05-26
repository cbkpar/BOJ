#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long lN, lC, lW;
	cin >> lN >> lC >> lW;

	vector<int> vecLen(lN, 0);
	for (int i = 0; i < lN; ++i) cin >> vecLen[i];

	long long lAns = 0;
	for (long long i = 1; i <= 10000; ++i)
	{
		long long lTotal = 0;
		for (int j = 0; j < lN; ++j)
		{
			long long lTemp = (vecLen[j] - 1) / i;
			long long lCost = 0;
			lCost += (vecLen[j] / i) * i * lW;
			lCost -= lTemp * lC;
			if (lCost > 0) lTotal += lCost;
		}
		if (lTotal > lAns) lAns = lTotal;
	}
	cout << lAns << "\n";
	return 0;
}
