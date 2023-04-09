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

	int iN;
	cin >> iN;
	vector<pair<long long, long long>> vecPos(iN, { 0, 0 });
	for (int i = 0; i < iN; ++i)
	{
		cin >> vecPos[i].first >> vecPos[i].second;
	}

	long long lMax = 1LL << 62;
	int iIndex = 0;
	for (int i = 1; i < iN; ++i)
	{
		long long lDiffX = (vecPos[i].first - vecPos[0].first);
		long long lDiffY = (vecPos[i].second - vecPos[0].second);
		if (lMax > lDiffX * lDiffX + lDiffY * lDiffY)
		{
			lMax = lDiffX * lDiffX + lDiffY * lDiffY;
			iIndex = i;
		}
	}
	cout << vecPos[0].first << " " << vecPos[0].second << "\n";
	cout << vecPos[iIndex].first << " " << vecPos[iIndex].second << "\n";

	cout << fixed;
	cout.precision(2);
	cout << sqrt((double)(lMax)) << "\n";
	return 0;
}
