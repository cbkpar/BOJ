#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;
	vector<pair<int, pair<long long, long long>>> vecRobot(iN);
	for (int i = 0; i < iN; ++i)
	{
		long long lX, lY, lV;
		cin >> lX >> lY >> lV;
		vecRobot[i].first = i + 1;
		vecRobot[i].second.first = lX * lX + lY * lY;
		vecRobot[i].second.second = lV * lV;
	}

	sort(vecRobot.begin(), vecRobot.end(), [](
		const pair<int, pair<long long, long long>>& o1,
		const pair<int, pair<long long, long long>>& o2)->bool
		{
			if(o1.second.first * o2.second.second != o2.second.first * o1.second.second)
			{
				return o1.second.first * o2.second.second < o2.second.first * o1.second.second;
			}
			return o1.first < o2.first;
		});
	for (int i = 0; i < iN; ++i)
	{
		cout << vecRobot[i].first << "\n";
	}
	return 0;
}
