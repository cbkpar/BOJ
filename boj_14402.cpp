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

	int iAns = 0;
	map<string, int> mapName;

	for (int i = 0; i < iN; ++i)
	{
		string strName;
		cin >> strName;

		string strCommand;
		cin >> strCommand;

		if (strCommand == "-")
		{
			if (mapName.find(strName) == mapName.end())
			{
				++iAns;
			}
			else
			{
				if (--mapName[strName] == 0)
				{
					mapName.erase(mapName.find(strName));
				}
			}
		}
		else
		{
			if (mapName.find(strName) == mapName.end())
			{
				mapName.insert({ strName, 1 });
			}
			else
			{
				++mapName[strName];
			}
		}
	}

	for (auto iter : mapName)
	{
		iAns += iter.second;
	}
	cout << iAns << "\n";
	return 0;
}
