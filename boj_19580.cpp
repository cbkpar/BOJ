#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;

	vector<pair<long long, long long>> vecInfo(iN, { 0,0 });
	for (int i = 0; i < iN; ++i)
	{
		cin >> vecInfo[i].first >> vecInfo[i].second;
	}

	sort(vecInfo.begin(), vecInfo.end(), [](const pair<long long, long long>& o1, const pair<long long, long long>& o2)->bool
		{
			if (o1.first == o2.first) return o1.second < o2.second;
			return o1.first < o2.first;
		});

	vector<pair<long long, long long>> vecStore(iM, { 0,0 });
	for (int i = 0; i < iM; ++i)
	{
		cin >> vecStore[i].first >> vecStore[i].second;
	}
	sort(vecStore.begin(), vecStore.end(), [](const pair<long long, long long>& o1, const pair<long long, long long>& o2)->bool
		{
			if (o1.first == o2.first) return o1.second < o2.second;
			return o1.first < o2.first;
		});

	int iAns = 0;
	int iNow = 0;
	priority_queue<long long, vector<long long>, greater<>> pq;

	for (int i = 0; i < iM; ++i)
	{
		long long lPrice = vecStore[i].first;
		long long lCount = vecStore[i].second;

		while (!pq.empty())
		{
			if (pq.top() >= lPrice)
			{
				break;
			}
			pq.pop();
		}

		while (iNow < iN && vecInfo[iNow].first <= lPrice)
		{
			pq.push(vecInfo[iNow++].second);
		}

		while (!pq.empty() && lCount > 0)
		{
			if (pq.top() < lPrice)
			{
				pq.pop();
			}
			else
			{
				++iAns;
				--lCount;
				pq.pop();
			}
		}
	}

	cout << iAns << "\n";
	return 0;
}
