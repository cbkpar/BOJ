#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long gcd(long long lA, long long lB)
{
	if (lB % lA == 0) return lA;
	return gcd(lB % lA, lA);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long lX, lY;
	cin >> lX >> lY;

	vector<pair<long long, long long>> vecMinus;
	vector<pair<long long, long long>> vecPlus;

	int iN;
	cin >> iN;
	while (iN--)
	{
		long long lTempX, lTempY;
		cin >> lTempX >> lTempY;

		lTempX -= lX;
		lTempY -= lY;
		if (lTempX == 0 || lTempY >= 0) continue;

		if (lTempX < 0)
		{
			lTempX = abs(lTempX) * abs(lTempX);
			lTempY = abs(lTempY);
			long long lGCD = (lTempX < lTempY ? gcd(lTempX, lTempY) : gcd(lTempY, lTempX));
			lTempX /= lGCD;
			lTempY /= lGCD;
			vecMinus.push_back({ lTempX, lTempY });
		}
		else
		{
			lTempX = abs(lTempX) * abs(lTempX);
			lTempY = abs(lTempY);
			int lGCD = (lTempX < lTempY ? gcd(lTempX, lTempY) : gcd(lTempY, lTempX));
			lTempX /= lGCD;
			lTempY /= lGCD;
			vecPlus.push_back({ lTempX, lTempY });
		}
	}

	int iAns = 0;
	if (vecMinus.size() > 0)
	{
		sort(vecMinus.begin(), vecMinus.end(), [](pair<long long, long long> o1, pair<long long, long long> o2)->bool
			{
				if (o1.first == o2.first)
				{
					return o1.second < o2.second;
				}
				return o1.first < o2.first;
			});

		iAns = max(iAns, 1);
		int iCount = 1;
		int iSize = vecMinus.size();
		for (int i = 1; i < iSize; ++i)
		{
			if (vecMinus[i].first == vecMinus[i - 1].first && vecMinus[i].second == vecMinus[i - 1].second)
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
	if (vecPlus.size() > 0)
	{
		sort(vecPlus.begin(), vecPlus.end(), [](pair<long long, long long> o1, pair<long long, long long> o2)->bool
			{
				if (o1.first == o2.first)
				{
					return o1.second < o2.second;
				}
				return o1.first < o2.first;
			});
		iAns = max(iAns, 1);
		int iCount = 1;
		int iSize = vecPlus.size();
		for (int i = 1; i < iSize; ++i)
		{
			if (vecPlus[i].first == vecPlus[i - 1].first && vecPlus[i].second == vecPlus[i - 1].second)
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
