#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	for (int t = 1; t <= iT; ++t)
	{
		int iN;
		cin >> iN;
		vector<pair<int, int>> vecNum(iN, { 0,0 });
		for (int i = 0; i < iN; ++i)
		{
			cin >> vecNum[i].first >> vecNum[i].second;
		}
		sort(vecNum.begin(), vecNum.end());
		int iAns = 0;
		for (int i = 0; i < iN; ++i)
		{
			for (int j = i + 1; j < iN; ++j)
			{
				if (vecNum[i].second > vecNum[j].second)
				{
					++iAns;
				}
			}
		}
		cout << "Case #" << t << ": " << iAns << "\n";
	}

	return 0;
}
