#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iK;
	cin >> iN >> iK;

	vector<pair<int, pair<long long, long long>>> vecInfo(iN, pair<int, pair<long long, long long>>());

	for (int i = 0;i < iN;++i)
	{
		int iNum;
		cin >> iNum;

		int iC, iH;
		cin >> iC >> iH;

		vecInfo[iNum - 1].first = iNum;
		vecInfo[iNum - 1].second.first = iC;
		vecInfo[iNum - 1].second.second = iH;
	}

	sort(vecInfo.begin(), vecInfo.end(), [](const pair<int, pair<long long, long long>>& o1, const pair<int, pair<long long, long long>>& o2)->bool
		{
			if (o1.second.second * o2.second.first == o2.second.second * o1.second.first)
			{
				if (o1.second.first == o2.second.first)
				{
					return o1.first < o2.first;
				}
				return o1.second.first < o2.second.first;
			}
			return o1.second.second * o2.second.first > o2.second.second * o1.second.first;
		});

	for (int i = 0;i < iK;++i)
	{
		cout << (vecInfo[i].first) << "\n";
	}
	return 0;
}
