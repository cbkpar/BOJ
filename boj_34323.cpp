#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long lN, lM, lS;
	cin >> lN >> lM >> lS;

	long long lCostSale = lS * (100 - lN) * (lM + 1) / 100;
	long long lCostPlus = lS * lM;

	long long lAns = min(lCostSale, lCostPlus);
	cout << lAns << "\n";

	return 0;
}
