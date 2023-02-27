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

	vector<int> vecCount(iN + 1, 0);
	vector<vector<int>> vecNode(iN + 1);
	priority_queue<long long, vector<long long>, greater<>> pq;
	while (iK--)
	{
		int iS, iE;
		cin >> iS >> iE;
		++vecCount[iE];
		vecNode[iS].push_back(iE);
	}
	for (int i = 1; i <= iN; ++i)
	{
		if (vecCount[i] == 0)
		{
			pq.push(i);
		}
	}
	while (!pq.empty())
	{
		int iNum = pq.top();
		pq.pop();
		for (int iNext : vecNode[iNum])
		{
			if (--vecCount[iNext] == 0)
			{
				pq.push(iNext);
			}
		}
		cout << iNum << (pq.empty() ? "\n" : " ");
	}

	return 0;
}
