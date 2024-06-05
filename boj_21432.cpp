#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iA, iB;
	cin >> iN >> iA >> iB;

	vector<pair<int, int>> vecCost(iN, { 0,0 });
	for (int i = 0;i < iN;++i)
	{
		cin >> vecCost[i].first >> vecCost[i].second;
	}

	double dAns = 0;
	for (int i = 0;i < iN;++i)
	{
		for (int j = 0;j < iN;++j)
		{
			double dTemp = 0;
			if (i == j)
			{
				dTemp = max(dTemp, (double)(iA) / (double)(vecCost[i].first));
				dTemp = max(dTemp, (double)(iB) / (double)(vecCost[i].second));
			}
			else
			{
				dTemp += (double)(iA) / (double)(vecCost[i].first);
				dTemp += (double)(iB) / (double)(vecCost[j].second);
			}
			dAns = max(dAns, dTemp);
		}
	}

	printf("%.2f\n", dAns);
	return 0;
}
