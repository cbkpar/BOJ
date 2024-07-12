#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;
	vector<pair<string, string>> vecName(iN, { "","" });
	for (int i = 0;i < iN;++i)
	{
		cin >> vecName[i].first >> vecName[i].second;
	}
	sort(vecName.begin(), vecName.end(), [](const pair<string, string>& o1, const pair<string, string>& o2)->bool
		{
			if (o1.second == o2.second) return o1.first.compare(o2.first) < 0;
			return o1.second.compare(o2.second) < 0;
		});

	map<string, int> mapName;
	for (int i = 0;i < iN;++i)
	{
		mapName.insert({ vecName[i].first + " " + vecName[i].second,i });
	}

	int iQ;
	cin >> iQ;
	while (iQ-- > 0)
	{
		string strNameFirst, strNameSecond;
		cin >> strNameFirst >> strNameSecond;
		int iIndex = mapName[strNameFirst + " " + strNameSecond];
		int iStart = (iIndex / 3) * 3;
		for (int i = iStart;i < iStart + 3;++i)
		{
			if (i == iIndex) continue;
			cout << vecName[i].first << " " << vecName[i].second << "\n";
		}
	}

	return 0;
}
