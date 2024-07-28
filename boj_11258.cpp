#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<pair<int, int>> vecInfo(6, { 0,0 });
	for (int i = 0;i < 6;++i)
	{
		cin >> vecInfo[i].first >> vecInfo[i].second;
	}

	while (true)
	{
		int iNum;
		cin >> iNum;
		if (iNum == -1) break;

		int iAns = 0;
		if (iNum == vecInfo[0].first) iAns += vecInfo[0].second;
		if (iNum / 1000 == vecInfo[1].first) iAns += vecInfo[1].second;
		if (iNum / 1000 == vecInfo[2].first) iAns += vecInfo[2].second;
		if (iNum % 1000 == vecInfo[3].first) iAns += vecInfo[3].second;
		if (iNum % 1000 == vecInfo[4].first) iAns += vecInfo[4].second;
		if (iNum % 100 == vecInfo[5].first) iAns += vecInfo[5].second;
		cout << iAns << "\n";
	}

	return 0;
}
