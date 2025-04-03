#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	for (int t = 1;t <= iT;++t)
	{
		int iN, iS, iP;
		cin >> iN >> iS >> iP;

		vector<pair<int, int>> vecPos(iN+1, { 0,0 });
		for (int i = 0;i <= iN;++i)
		{
			cin >> vecPos[i].first >> vecPos[i].second;
		}

		int iSum = 0;
		for (int i = 1;i <= iN;++i)
		{
			iSum += abs(vecPos[i].first - vecPos[i - 1].first);
			iSum += abs(vecPos[i].second - vecPos[i - 1].second);
		}

		int iAns = (iSum * iS + iP - 1) / iP;
		if (t > 1) cout << "\n";
		cout << "Data Set " << t << ":\n";
		cout << iAns << "\n";
	}
	return 0;
}
