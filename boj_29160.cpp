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

	vector<priority_queue<long long, vector<long long>, less<>>> pq(12, priority_queue<long long, vector<long long>, less<>>());

	for (int i = 0; i < iN; ++i)
	{
		int iP, iW;
		cin >> iP >> iW;

		pq[iP].push(iW);
	}

	while (iK--)
	{
		for (int i = 1; i <= 11; ++i)
		{
			if (!pq[i].empty())
			{
				int iP = pq[i].top();
				pq[i].pop();
				--iP;
				if (iP == 0) iP = 1;
				pq[i].push(iP);
			}
		}
	}

	int iSum = 0;
	for (int i = 1; i <= 11; ++i)
	{
		if (pq[i].empty()) continue;
		iSum += pq[i].top();
	}

	cout << iSum << "\n";
	return 0;
}
