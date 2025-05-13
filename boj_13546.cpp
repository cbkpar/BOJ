#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <math.h>
#include <list>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iK;
	cin >> iN >> iK;

	int iSqrt = (int)sqrt(iN);

	vector<int> vecNum(iN + 1, 0);
	for (int i = 1;i <= iN;++i)
	{
		cin >> vecNum[i];
	}

	vector<tuple<int, int, int>> vecQuery;

	int iM;
	cin >> iM;
	for (int t = 0;t < iM;++t)
	{
		int iL, iR;
		cin >> iL >> iR;
		vecQuery.push_back(make_tuple(iL, iR, t));
	}

	sort(vecQuery.begin(), vecQuery.end(), [&](const tuple<int, int, int>& o1, const tuple<int, int, int>& o2)->bool
		{
			if (get<0>(o1) / iSqrt == get<0>(o2) / iSqrt) return get<1>(o1) < get<1>(o2);
			return get<0>(o1) < get<0>(o2);
		});


	vector<list<int>> vecList(iK + 1, list<int>());

	int iSize = (iN / iSqrt) + 1;
	vector<int> vecCount(iN + 1, 0);
	vector<int> vecBucket(iSize + 1, 0);

	vector<int> vecAns(iM, 0);
	int iS = 0;
	int iE = 0;

	for (int t = 0;t < iM;++t)
	{
		int iL = get<0>(vecQuery[t]);
		int iR = get<1>(vecQuery[t]);
		int iIndex = get<2>(vecQuery[t]);

		while (iE < iR)
		{
			++iE;
			if (vecList[vecNum[iE]].size() > 0)
			{
				int iBefore = vecList[vecNum[iE]].back() - vecList[vecNum[iE]].front();
				--vecBucket[iBefore / iSqrt];
				--vecCount[iBefore];
			}
			vecList[vecNum[iE]].push_back(iE);
			int iAfter = vecList[vecNum[iE]].back() - vecList[vecNum[iE]].front();
			++vecBucket[iAfter / iSqrt];
			++vecCount[iAfter];
		}
		while (iS >= iL)
		{
			if (vecList[vecNum[iS]].size() > 0)
			{
				int iBefore = vecList[vecNum[iS]].back() - vecList[vecNum[iS]].front();
				--vecBucket[iBefore / iSqrt];
				--vecCount[iBefore];
			}
			vecList[vecNum[iS]].push_front(iS);
			int iAfter = vecList[vecNum[iS]].back() - vecList[vecNum[iS]].front();
			++vecBucket[iAfter / iSqrt];
			++vecCount[iAfter];
			--iS;
		}
		while (iE > iR)
		{
			int iBefore = vecList[vecNum[iE]].back() - vecList[vecNum[iE]].front();
			--vecBucket[iBefore / iSqrt];
			--vecCount[iBefore];
			vecList[vecNum[iE]].pop_back();
			if (vecList[vecNum[iE]].size() > 0)
			{
				int iAfter = vecList[vecNum[iE]].back() - vecList[vecNum[iE]].front();
				++vecBucket[iAfter / iSqrt];
				++vecCount[iAfter];
			}
			--iE;
		}
		while (iS + 1 < iL)
		{
			++iS;
			int iBefore = vecList[vecNum[iS]].back() - vecList[vecNum[iS]].front();
			--vecBucket[iBefore / iSqrt];
			--vecCount[iBefore];
			vecList[vecNum[iS]].pop_front();
			if (vecList[vecNum[iS]].size() > 0)
			{
				int iAfter = vecList[vecNum[iS]].back() - vecList[vecNum[iS]].front();
				++vecBucket[iAfter / iSqrt];
				++vecCount[iAfter];
			}
		}

		for (int i = iSize;i >= 0;--i)
		{
			if (vecBucket[i] > 0)
			{
				for (int j = iSqrt - 1;j >= 0;--j)
				{
					if (i * iSqrt + j >= iN) continue;
					if (vecCount[i * iSqrt + j] > 0)
					{
						vecAns[iIndex] = i * iSqrt + j;
						break;
					}
				}
				break;
			}
		}
	}

	for (int i = 0;i < iM;++i)
	{
		cout << vecAns[i] << "\n";
	}

	return 0;
}
