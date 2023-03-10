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

	int iN;
	cin >> iN;

	vector<pair<int, int>> vecSub(iN);
	for (int i = 0; i < iN; ++i)
	{
		cin >> vecSub[i].first >> vecSub[i].second;
	}
	sort(vecSub.begin(), vecSub.end());
	int iIndex = 0;
	priority_queue<long long, vector<long long>, greater<>> pq;
	for (int i = 1; i <= 1000; ++i)
	{
		while (iIndex < iN && vecSub[iIndex].first <= i)
		{
			pq.push(vecSub[iIndex].second);
			++iIndex;
		}
		while (pq.size() > i) pq.pop();
	}
	int iSum = 0;
	while (!pq.empty())
	{
		iSum += pq.top();
		pq.pop();
	}
	cout << iSum << "\n";
	return 0;
}
