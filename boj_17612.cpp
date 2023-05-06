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

	int iN, iK;
	cin >> iN >> iK;

	vector<pair<long long, int>> vecNum(iN, { 0,0 });
	for (int i = 0; i < iN; ++i)
	{
		cin >> vecNum[i].first >> vecNum[i].second;
	}
	int iIndex = 0;

	long long lAns = 0;
	int iNow = 0;
	int iUse = 0;
	long long lCount = 1;
	vector<priority_queue<pair<int, long long>, vector<pair<int, long long>>, greater<>>> pq(20, priority_queue<pair<int, long long>, vector<pair<int, long long>>, greater<>>());
	priority_queue<int, vector<int>, less<>> pqWait;
	for (int i = 0; i < iK; ++i)
	{
		pqWait.push(i);
	}
	while (true)
	{
		while (!pq[iNow].empty())
		{
			pair<int,long long> tNum = pq[iNow].top();
			pq[iNow].pop();
			--iUse;
			lAns += tNum.second * lCount;
			pqWait.push(tNum.first);
			++lCount;
		}
		while (iUse < iK && iIndex < iN)
		{
			pq[(iNow + vecNum[iIndex].second) % 20].push({ pqWait.top(), vecNum[iIndex].first });
			pqWait.pop();
			++iIndex;
			++iUse;
		}
		if (iUse == 0 && iIndex == iN) break;
		iNow = (iNow + 1) % 20;
	}
	cout << lAns << "\n";
	return 0;
}
