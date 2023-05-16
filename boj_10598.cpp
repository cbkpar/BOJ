#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;

	vector<pair<int, int>> vecCar(iN, { 0,0 });
	vector<int> vecDiff(iN, 0);
	for (int i = 0; i < iN; ++i)
	{
		cin >> vecCar[i].first >> vecCar[i].second;
		vecDiff[i] = vecCar[i].second - vecCar[i].first;
	}

	while (iM--)
	{
		int iS, iE, iT;
		cin >> iS >> iE >> iT;

		int iAns = 0;
		for (int i = 0; i < iN; ++i)
		{
			int iTempT = iT % (vecDiff[i] * 2);
			int iPos = (iTempT >= vecDiff[i] ? vecCar[i].second - (iTempT - vecDiff[i]) : vecCar[i].first + iTempT);
			if (iPos >= iS && iPos <= iE) ++iAns;
		}
		cout << iAns << "\n";
	}
	return 0;
}
