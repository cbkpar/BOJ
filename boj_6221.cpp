#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int g_iAns = 0;
int iN;
vector<pair<int, int>> vecSize;

void DFS(int iK, int iA, int iB, int iS)
{
	g_iAns = max(g_iAns, iS);
	if (iK >= iN) return;

	if (vecSize[iK].first <= iA && vecSize[iK].second <= iB)
	{
		DFS(iK + 1, vecSize[iK].first, vecSize[iK].second, iS + 1);
	}
	DFS(iK + 1, iA, iB, iS);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> iN;

	for (int i = 0;i < iN;++i)
	{
		int iA, iB;
		cin >> iA >> iB;
		vecSize.push_back({ iA, iB });
	}

	sort(vecSize.begin(), vecSize.end(), [](const pair<int, int>& o1, const pair<int, int>& o2)->bool
		{
			if (o1.first == o2.first) return o1.second > o2.second;
			return o1.first > o2.first;
		});

	DFS(0, 999999999, 999999999, 0);
	cout << g_iAns << "\n";
	return 0;
}
