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

	int iT;
	cin >> iT;
	while (iT--)
	{
		int iN;
		cin >> iN;
		long long lSum = 0;
		priority_queue<long long, vector<long long>,greater<>> pq;

		for (int i = 0; i < iN; ++i)
		{
			long long lSize;
			cin >> lSize;
			pq.push(lSize);
		}
		for (int i = 1; i < iN; ++i)
		{
			long long lTemp = pq.top();
			pq.pop();
			lTemp += pq.top();
			pq.pop();
			lSum += lTemp;
			pq.push(lTemp);
		}
		cout << lSum << "\n";
	}
	return 0;
}
