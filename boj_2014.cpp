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

	int iK, iN;
	cin >> iK >> iN;
	vector<long long> vecNum(iK);
	for (int i = 0; i < iK; ++i) cin >> vecNum[i];

	int iCount = 0;
	priority_queue<long long, vector<long long>, greater<>> pq;
	for (int i = 0; i < iK; ++i)
	{
		pq.push(vecNum[i]);
	}

	for (int i = 1; i < iN; ++i)
	{
		long long lNum = pq.top();
		pq.pop();
		for (int j = 0; j < iK; ++j)
		{
			long long lNextNum = lNum * vecNum[j];
			pq.push(lNextNum);
			if (lNum % vecNum[j] == 0) break;
		}
	}
	cout << pq.top() << "\n";

	return 0;
}
