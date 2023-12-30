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

	vector<long long> vecHeight(iN, 0);
	for (int i = 0; i < iN; ++i) cin >> vecHeight[i];

	long long lAns = 0;
	for (int i = 0; i < iN; ++i)
	{
		lAns += vecHeight[i] * 4 + 2;
	}
	for (int i = 1; i < iN; ++i)
	{
		lAns -= min(vecHeight[i], vecHeight[i - 1]) * 2;
	}
	cout << lAns << "\n";
	return 0;
}
