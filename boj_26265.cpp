#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;
	vector<pair<string, string>> vecPair(iN, { "","" });
	for (int i = 0; i < iN; ++i)
	{
		cin >> vecPair[i].first >> vecPair[i].second;
	}
	sort(vecPair.begin(), vecPair.end(), [](const pair<string, string>& o1, const pair<string, string>& o2)->bool
		{
			if (o1.first == o2.first) return o1.second.compare(o2.second) > 0;
			return o1.first.compare(o2.first) < 0;
		});
	for (int i = 0; i < iN; ++i)
	{
		cout << vecPair[i].first << " " << vecPair[i].second << "\n";
	}
	return 0;
}
