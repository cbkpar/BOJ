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

	vector<pair<int, int>> vecCup(iN, { 0,0 });
	for (int i = 0;i < iN;++i)
	{
		cin >> vecCup[i].first >> vecCup[i].second;
	}

	sort(vecCup.begin(), vecCup.end(), [](const pair<int, int>& o1, const pair<int, int>& o2)->bool {
		if (o1.first == o2.first) return o2.second - o1.second < 0;
		return o1.first - o2.first < 0;
		});

	priority_queue<int, vector<int>, greater<int>> pq;
	int iSum = 0;

	for (int i = 0;i < iN;++i)
	{
		int iTime = vecCup[i].first;
		int iCount = vecCup[i].second;
		iSum += iCount;
		pq.push(iCount);

		if (pq.size() > iTime)
		{
			iSum -= pq.top();
			pq.pop();
		}
	}

	cout << iSum << "\n";
	return 0;
}
