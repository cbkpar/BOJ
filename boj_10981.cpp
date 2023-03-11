#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iK;
	cin >> iN >> iK;

	vector<pair<pair<string, string>, pair<int, int>>> vecTeam;
	for (int i = 0; i < iN; ++i)
	{
		pair<pair<string, string>, pair<int, int>> vecTemp;
		cin >> vecTemp.first.first >> vecTemp.first.second >> vecTemp.second.first >> vecTemp.second.second;
		vecTeam.push_back(vecTemp);
	}

	sort(vecTeam.begin(), vecTeam.end(), [](const pair<pair<string, string>, pair<int, int>>& o1, const pair<pair<string, string>, pair<int, int>>& o2)->bool
		{
			if (o1.second.first == o2.second.first)
			{
				return o1.second.second < o2.second.second;
			}
			return o1.second.first > o2.second.first;
		});

	set<string> setName;
	for (int i = 0; i < iN; ++i)
	{
		if (setName.find(vecTeam[i].first.first) == setName.end())
		{
			cout << vecTeam[i].first.second << "\n";
			setName.insert(vecTeam[i].first.first);
			--iK;
		}
		if (iK == 0) break;
	}
	return 0;
}
