#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long CalcArea(const pair<long long, long long>& pA, const pair<long long, long long>& pB)
{
	return (pA.first - pB.first) * (pA.first - pB.first) + (pA.second - pB.second) * (pA.second - pB.second);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;

	vector<pair<long long, long long>> vecN(iN, { 0,0 });
	vector<pair<long long, long long>> vecM(iM, { 0,0 });

	for (int i = 0; i < iN; ++i)
	{
		cin >> vecN[i].first >> vecN[i].second;
	}
	for (int i = 0; i < iM; ++i)
	{
		cin >> vecM[i].first >> vecM[i].second;
	}

	long long lAns = 0;
	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iM; ++j)
		{
			long long lTemp = CalcArea(vecN[i], vecM[j]);
			lAns = max(lAns, lTemp);
		}
	}
	
	cout << lAns << "\n";
	return 0;
}
