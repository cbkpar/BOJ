#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<pair<int, int>> vecPos(3, { 0,0 });
	for (int i = 0;i < 3;++i)
	{
		cin >> vecPos[i].first >> vecPos[i].second;
	}
	sort(vecPos.begin(), vecPos.end());

	bool bStraight = false;
	if (vecPos[0].first == vecPos[1].first && vecPos[1].first == vecPos[2].first)
	{
		bStraight = true;
	}
	else
	{
		int iSlope1 = (vecPos[1].second - vecPos[0].second) * (vecPos[2].first - vecPos[1].first);
		int iSlope2 = (vecPos[2].second - vecPos[1].second) * (vecPos[1].first - vecPos[0].first);
		if (iSlope1 == iSlope2)
		{
			bStraight = true;
		}
	}

	if(bStraight)
	{
		cout << "WHERE IS MY CHICKEN?" << "\n";
	}
	else
	{
		cout << "WINNER WINNER CHICKEN DINNER!" << "\n";
	}
	return 0;
}
