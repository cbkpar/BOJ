#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<pair<int, int>> vecInfo(3, { 0,0 });
	for (int i = 0;i < 3;++i)
	{
		cin >> vecInfo[i].first >> vecInfo[i].second;
	}

	int iHp;
	cin >> iHp;

	vector<int> vecTime(3, 0);
	int iTime = 0;

	for (int i = 0;i < 3;++i)
	{
		iHp -= vecInfo[i].second;
		vecTime[i] += vecInfo[i].first;
	}

	while (iHp > 0)
	{
		++iTime;
		for (int i = 0;i < 3;++i)
		{
			if (iTime >= vecTime[i])
			{
				iHp -= vecInfo[i].second;
				vecTime[i] += vecInfo[i].first;
			}
		}
	}

	cout << iTime;
	return 0;
}
