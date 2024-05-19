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

	long long lAns = 0;
	vector<long long> vecPrice(iN, 0);
	for (int i = 0; i < iN; ++i)
	{
		cin >> vecPrice[i];
	}

	long long lMin = vecPrice[0];
	for (int i = 1; i < iN; ++i)
	{
		lMin = min(lMin, vecPrice[i]);
		lAns = max(lAns, vecPrice[i] - lMin);
	}

	cout << lAns << "\n";
	return 0;
}
