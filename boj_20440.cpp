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

	vector<pair<int, int>> vecTime(iN, { 0,0 });
	for (int i = 0;i < iN;++i)
	{
		cin >> vecTime[i].first >> vecTime[i].second;
	}

	sort(vecTime.begin(), vecTime.end(), [](const pair<int, int>& o1, const pair<int, int>& o2)->bool
		{
			if (o1.first == o2.first) return o1.second > o2.second;
			return o1.first < o2.first;
		});

	int iAns = 0;
	int iAnsS = 0;
	int iAnsE = 0;

	priority_queue<int, vector<int>, greater<>> pq;

	for (int i = 0;i < iN;++i)
	{
		int iS = vecTime[i].first;
		int iE = vecTime[i].second;
		while (!pq.empty())
		{
			if (pq.top() > iS) break;
			pq.pop();
		}
		pq.push(iE);

		if (pq.size() > iAns)
		{
			iAns = pq.size();
			iAnsS = iS;
			iAnsE = pq.top();
		}
		else if (pq.size() == iAns)
		{
			if (iAnsE >= iS)
			{
				iAnsE = max(iAnsE, iE);
			}
		}

	}

	cout << iAns << "\n";
	cout << iAnsS << " " << iAnsE << "\n";
	return 0;
}
