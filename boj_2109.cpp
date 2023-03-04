#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	int iN;
	cin >> iN;

	vector<pair<int, int>> vecNum(iN, { 0,0 });
	for (int i = 0; i < iN; ++i)
	{
		cin >> vecNum[i].second >> vecNum[i].first;
	}

	sort(vecNum.begin(), vecNum.end());
	priority_queue<long long, vector<long long>, greater<>> pq;

	int iAns = 0;
	vecNum.push_back({ 10001,0 });
	int iIndex = 0;
	for (int i = 1; i <= 10000; ++i)
	{
		while (vecNum[iIndex].first <= i)
		{
			pq.push(vecNum[iIndex++].second);
		}
		while (pq.size() > i)
		{
			pq.pop();
		}
	}
	while (!pq.empty())
	{
		iAns += pq.top();
		pq.pop();
	}
	cout << iAns << "\n";
	return 0;
}
