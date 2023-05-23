#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true)
	{
		int iN;
		cin >> iN;
		if (iN == 0) break;
		vector<pair<int, int>> vecCount(150, { 0,0 });

		while (iN--)
		{
			int iY;
			cin >> iY;
			string strType, strMedal;
			cin >> strType >> strMedal;

			++vecCount[iY - 1896].second;
			if (strMedal == "Gold")
			{
				++vecCount[iY - 1896].first;
			}
		}
		int iAnsYear1 = 0;
		int iAnsCount1 = -1;
		int iAnsYear2 = 0;
		int iAnsCount2 = -1;
		for (int i = 0; i < 150; ++i)
		{
			if (vecCount[i].first > iAnsCount1)
			{
				iAnsCount1 = vecCount[i].first;
				iAnsYear1 = i + 1896;
			}
			if (vecCount[i].second > iAnsCount2)
			{
				iAnsCount2 = vecCount[i].second;
				iAnsYear2 = i + 1896;
			}
		}
		cout << iAnsYear1 << " " << iAnsYear2 << "\n";
	}
	return 0;
}
