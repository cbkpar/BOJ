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

	vector<pair<int, int>> vecMonitor(iN, { 0,0 });
	for (int i = 1; i <= iN; ++i)
	{
		int iW, iH;
		cin >> iW >> iH;
		int iTotal = iW * iW + iH * iH;
		vecMonitor[i - 1].first = i;
		vecMonitor[i - 1].second = iTotal;
	}
	sort(vecMonitor.begin(), vecMonitor.end(),
		[&](const pair<int, int>& o1, const pair<int, int>& o2)->bool
		{
			if (o1.second == o2.second)
			{
				return o1.first < o2.first;
			}
			return o1.second > o2.second;
		});
	for (int i = 0; i < iN; ++i)
	{
		cout << vecMonitor[i].first << "\n";
	}
	return 0;
}
