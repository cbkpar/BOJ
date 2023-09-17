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

	vector<pair<long long, pair<long long, long long>>> vecItem(iN, { 0,{0,0} });
	for (int i = 0; i < iN; ++i)
	{
		cin >> vecItem[i].second.first >> vecItem[i].second.second;
		vecItem[i].first = vecItem[i].second.first - vecItem[i].second.second;
	}
	sort(vecItem.begin(), vecItem.end());

	long long lSum = 0;
	for (int i = 0; i < iA; ++i)
	{
		lSum += vecItem[i].second.first;
	}
	for (int i = iA; i < iN; ++i)
	{
		lSum += vecItem[i].second.second;
	}
	cout << lSum << "\n";
	return 0;
}
