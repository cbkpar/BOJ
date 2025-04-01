#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;
	vector<pair<double, double>> vecPos(iN, { 0,0 });
	for (int i = 0;i < iN;++i)
	{
		cin >> vecPos[i].first >> vecPos[i].second;
	}

	int iT;
	cin >> iT;
	while (iT-- > 0)
	{
		int iRoute;
		cin >> iRoute;
		vector<int> vecRoute(iRoute, 0);
		for (int i = 0;i < iRoute;++i)
		{
			cin >> vecRoute[i];
		}

		double dSum = 0;
		for (int i = 1;i < iRoute;++i)
		{
			double dX = vecPos[vecRoute[i]].first - vecPos[vecRoute[i - 1]].first;
			double dY = vecPos[vecRoute[i]].second - vecPos[vecRoute[i - 1]].second;
			dSum += sqrt(dX * dX + dY * dY);
		}
		cout << (long long)round(dSum) << "\n";
	}

	return 0;
}
