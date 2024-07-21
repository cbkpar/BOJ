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

	vector<pair<int, int>> vecInfo(iN, { 0,0 });
	for (int i = 0; i < iN; ++i)
	{
		cin >> vecInfo[i].first >> vecInfo[i].second;
	}

	sort(vecInfo.begin(), vecInfo.end());

	int iAns = 0;
	int iNow = -1;
	for (int i = 0; i < iN; ++i)
	{
		if (iNow >= vecInfo[i].first)
		{
			iNow = vecInfo[i].first + vecInfo[i].second;
			continue;
		}
		++iAns;
		iNow = vecInfo[i].first + vecInfo[i].second;
	}

	cout << iAns << "\n";
	return 0;
}
