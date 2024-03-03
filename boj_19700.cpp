#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	vector<pair<int, int>> vecNum(iN, { 0,0 });
	for (int i = 0;i < iN;++i)
	{
		cin >> vecNum[i].first >> vecNum[i].second;
	}
	sort(vecNum.begin(), vecNum.end(), greater<>());

	map<int, int> mapNum;

	int iAns = 0;
	for (int i = 0;i < iN;++i)
	{
		auto iter = mapNum.lower_bound(vecNum[i].second);
		if (iter == mapNum.begin())
		{
			++iAns;
			if (mapNum.find(1) == mapNum.end())
			{
				mapNum.insert({ 1, 1 });
			}
			else
			{
				mapNum[1] = mapNum[1] + 1;
			}
		}
		else
		{
			iter = prev(iter);
			int iNum = (*iter).first;
			if (mapNum.find(iNum + 1) == mapNum.end())
			{
				mapNum.insert({ iNum + 1, 1 });
			}
			else
			{
				mapNum[iNum + 1] = mapNum[iNum + 1] + 1;
			}

			if ((*iter).second == 1)
			{
				iter = mapNum.erase(iter);
			}
			else
			{
				mapNum[iNum] = mapNum[iNum] - 1;
			}
		}
	}

	cout << iAns << "\n";
	return 0;
}
