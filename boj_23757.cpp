#include <iostream>
#include <queue>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;
	priority_queue<int> pq;

	for (int i = 0; i < iN; ++i)
	{
		int iCount;
		cin >> iCount;
		pq.emplace(iCount);
	}
	while (iM--)
	{
		int iCount;
		cin >> iCount;
		int iMax = pq.top();
		pq.pop();
		if (iMax < iCount)
		{
			cout << "0\n";
			return 0;
		}
		if (iMax - iCount > 0)
		{
			pq.emplace(iMax - iCount);
		}
	}
	cout << "1\n";
	return 0;
}
