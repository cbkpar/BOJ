#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iIndex = 0;
	while (true)
	{
		++iIndex;
		bool bFirst = true;
		map<string, string> mapName;
		set<string> setName;
		vector<pair<string, string>> vecName;
		while (true)
		{
			string strNameA, strNameB;
			cin >> strNameA;
			if (strNameA == "#") break;
			cin >> strNameB;
			mapName.insert({ strNameA,strNameB });
			vecName.push_back({ strNameA,strNameB });
			bFirst = false;
		}
		if (bFirst) break;
		if (iIndex > 1) cout << "\n";
		cout << "Party number " << iIndex << "\n";
		for (pair<string, string> pName : vecName)
		{
			if (setName.find(pName.first) == setName.end())
			{
				cout << pName.first;
				string strTemp = pName.second;
				while (true)
				{
					if (setName.find(strTemp) != setName.end()) break;
					cout << " to " << strTemp;
					setName.insert(strTemp);
					strTemp = mapName.find(strTemp)->second;
				}
				cout << ".\n";
			}
		}
	}
	return 0;
}
