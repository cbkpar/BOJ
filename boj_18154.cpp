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
	for (int i = 0;i < iN;++i)
	{
		cin >> vecInfo[i].first >> vecInfo[i].second;
	}

	int iAns = 0;
	for (int i = 1;i < iN;++i)
	{
		int iDiff = (vecInfo[i].second - vecInfo[i - 1].second) / (vecInfo[i].first - vecInfo[i - 1].first);
		iAns = max(iAns, iDiff);
	}

	cout << iAns << "\n";
	return 0;
}
