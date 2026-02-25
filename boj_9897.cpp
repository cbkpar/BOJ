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
	std::cout.tie(NULL);

	int iL, iP, iT;
	cin >> iL >> iP >> iT;
	vector<int> vecCount(iL + 1, 0);

	map<string, pair<int, int>> mapPeople;
	for (int i = 0;i < iP;++i)
	{
		string strName;
		int iA, iD;
		cin >> strName >> iA >> iD;
		mapPeople.insert({ strName,{iA,iD} });
	}

	for (int i = 0;i < iT;++i)
	{
		string strName;
		cin >> strName;

		int iA = mapPeople[strName].first;
		int iD = mapPeople[strName].second;

		for (int j = iA;j <= iL;j += iD)
		{
			vecCount[j]++;
		}
	}

	int iAns = 0;
	for (int i = 1;i <= iL;++i)
	{
		if (vecCount[i] % 2 == 1)
		{
			++iAns;
		}
	}
	cout << iAns << "\n";

	return 0;
}
