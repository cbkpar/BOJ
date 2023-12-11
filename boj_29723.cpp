#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int main()
{
	int iN, iM, iK;
	cin >> iN >> iM >> iK;

	vector<pair<int, string>> vecSub(iN, { 0,"" });

	for (int i = 0;i < iN;++i)
	{
		cin >> vecSub[i].second >> vecSub[i].first;
	}
	sort(vecSub.begin(), vecSub.end());

	set<string> setSub;
	for (int i = 0;i < iK;++i)
	{
		string strSub;
		cin >> strSub;
		setSub.insert(strSub);
	}

	int iMax = 0;
	int iMin = 0;

	int iMaxCount = iM - iK;
	int iMinCount = iM - iK;
	for (int i = 0;i < iN;++i)
	{
		if (setSub.find(vecSub[i].second) == setSub.end())
		{
			if (iMinCount > 0)
			{
				--iMinCount;
				iMin += vecSub[i].first;
			}
		}
		else
		{
			iMin += vecSub[i].first;
		}
	}

	for (int i = iN-1;i >= 0;--i)
	{
		if (setSub.find(vecSub[i].second) == setSub.end())
		{
			if (iMaxCount > 0)
			{
				--iMaxCount;
				iMax += vecSub[i].first;
			}
		}
		else
		{
			iMax += vecSub[i].first;
		}
	}

	cout << iMin << " " << iMax << "\n";
	return 0;
}
