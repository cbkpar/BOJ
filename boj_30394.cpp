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

	long long lMax = -1000000000;
	long long lMin = 1000000000;
	vector<pair<long long, long long>> vecPos(iN, { 0,0 });
	for (int i = 0;i < iN;++i)
	{
		cin >> vecPos[i].first >> vecPos[i].second;
		lMax = max(lMax, vecPos[i].second);
		lMin = min(lMin, vecPos[i].second);
	}

	long long lAns = lMax - lMin;
	cout << lAns << "\n";
	return 0;
}
