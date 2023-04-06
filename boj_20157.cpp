#include <iostream>
#include <vector>
#include <algorithm>

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

	int iN;
	cin >> iN;

	vector<int> vecDir(4, 0);
	vector<vector<pair<int, int>>> vecPos(4, vector<pair<int, int>>());

	while (iN--)
	{
		int iX, iY;
		cin >> iX >> iY;

		if (iX == 0 || iY == 0)
		{
			int iDir = 0;
			if (iX == 0 && iY > 0) iDir = 0;
			if (iX == 0 && iY < 0) iDir = 1;
			if (iX > 0 && iY == 0) iDir = 2;
			if (iX < 0 && iY == 0) iDir = 3;
			++vecDir[iDir];
			continue;
		}

		int iPos = 0;
		if (iX > 0) iPos += 1;
		if (iY > 0) iPos += 2;
		iX = abs(iX);
		iY = abs(iY);

		int iGCD = gcd(iX, iY);
		iX /= iGCD;
		iY /= iGCD;

		vecPos[iPos].push_back({ iX,iY });
	}

	int iAns = 1;
	for (int i = 0; i < 4; ++i) iAns = max(iAns, vecDir[i]);

	for (int i = 0; i < 4; ++i)
	{
		sort(vecPos[i].begin(), vecPos[i].end(), [](pair<int, int> o1, pair<int, int> o2)->bool
			{
				if (o1.first == o2.first)
				{
					return o1.second < o2.second;
				}
				return o1.first < o2.first;
			});
	}

	for (int i = 0; i < 4; ++i)
	{
		int iCount = 1;
		int iSize = vecPos[i].size();
		for (int j = 1; j < iSize; ++j)
		{
			if (vecPos[i][j].first == vecPos[i][j - 1].first && vecPos[i][j].second == vecPos[i][j - 1].second)
			{
				++iCount;
			}
			else
			{
				iCount = 1;
			}
			iAns = max(iAns, iCount);
		}
	}
	cout << iAns << "\n";
	return 0;
}
