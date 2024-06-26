#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

bool IsCollision(pair<int, int> p1, pair<int, int> p2, int iR)
{
	int iDiffX = abs(p1.first - p2.first);
	int iDiffY = abs(p1.second - p2.second);
	if (iDiffX * iDiffX + iDiffY * iDiffY <= iR * iR)
	{
		return true;
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iR;
	cin >> iN >> iR;

	int iMinX = 100;
	int iMaxX = -100;
	int iMinY = 100;
	int iMaxY = -100;

	vector<pair<int, int>> vecPos(iN, { 0,0 });
	for (int i = 0;i < iN;++i)
	{
		cin >> vecPos[i].first >> vecPos[i].second;
		iMinX = min(iMinX, vecPos[i].first);
		iMaxX = max(iMaxX, vecPos[i].first);
		iMinY = min(iMinY, vecPos[i].second);
		iMaxY = max(iMaxY, vecPos[i].second);
	}

	int iMax = -1;
	pair<int, int> pAns = { 0,0 };

	for (int i = iMinX;i <= iMaxX;++i)
	{
		for (int j = iMinY;j <= iMaxY;++j)
		{
			pair<int, int> pTemp = { i,j };
			int iCount = 0;
			for (int k = 0;k < iN;++k)
			{
				if (IsCollision(pTemp, vecPos[k], iR))
				{
					++iCount;
				}
			}
			if (iCount > iMax)
			{
				iMax = iCount;
				pAns = pTemp;
			}
		}
	}

	cout << pAns.first << " " << pAns.second << "\n";
	return 0;
}
