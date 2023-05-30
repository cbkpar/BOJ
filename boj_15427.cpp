#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <math.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<pair<long long, long long>> vecPair;
	for (long long i = -2018; i <= 2018; ++i)
	{
		long long lTemp = 2018 * 2018 - i * i;
		long long lSqrt = (long long)sqrt(lTemp);
		if (lSqrt * lSqrt == lTemp)
		{
			vecPair.push_back({ i,lSqrt });
			if (lSqrt != 0) vecPair.push_back({ i,-lSqrt });
		}
	}
	int iSize = vecPair.size();

	int iN;
	cin >> iN;

	long long lAns = 0;
	map<long long, set<long long>> mapNum;

	while (iN--)
	{
		long long lX, lY;
		cin >> lX >> lY;
		for (int i = 0; i < iSize; ++i)
		{
			long long lNextX = lX + vecPair[i].first;
			long long lNextY = lY + vecPair[i].second;
			if (mapNum.find(lNextX) != mapNum.end())
			{
				if (mapNum[lNextX].find(lNextY) != mapNum[lNextX].end())
				{
					++lAns;
				}
			}
		}
		mapNum[lX].insert(lY);
	}

	cout << lAns << "\n";
	return 0;
}
