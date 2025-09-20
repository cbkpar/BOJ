#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int gcd(int iA, int iB)
{
	if (iB % iA == 0) return iA;
	return gcd(iB % iA, iA);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	set<int> setSlope;

	int iN;
	cin >> iN;
	vector<pair<int, int>> vecLine(iN, { 0,0 });
	for (int i = 0;i < iN;++i)
	{
		cin >> vecLine[i].first >> vecLine[i].second;
	}

	for (int i = 0;i < iN;++i)
	{
		for (int j = i + 1;j < iN;++j)
		{
			int dX = vecLine[j].first - vecLine[i].first;
			int dY = vecLine[j].second - vecLine[i].second;
			if (dX == 0)
			{
				setSlope.insert(0);
			}
			else
			{
				int iGCD = gcd(dX, dY);
				dX /= iGCD;
				dY /= iGCD;
				setSlope.insert(dX * 10000 + dY);
			}
		}
	}

	cout << setSlope.size() << "\n";
	return 0;
}
