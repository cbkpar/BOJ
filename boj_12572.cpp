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
		vector<pair<int, int>> vecLine(iN, { 0,0 });
		for (int i = 0; i < iN; ++i)
		{
			cin >> vecLine[i].first >> vecLine[i].second;
		}
		int iAns = 0;
		for (int i = 0; i < iN; ++i)
		{
			for (int j = i + 1; j < iN; ++j)
			{
				if (vecLine[i].first > vecLine[j].first && vecLine[i].second < vecLine[j].second) ++iAns;
				if (vecLine[i].first < vecLine[j].first && vecLine[i].second > vecLine[j].second) ++iAns;
			}
		}
		cout << "Case #" << t << ": " << iAns << "\n";
	}

	return 0;
}
