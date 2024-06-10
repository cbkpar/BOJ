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

	vector<pair<int, int>> vecDir(iT, { 0,0 });
	for (int i = 0; i < iT; ++i)
	{
		cin >> vecDir[i].first >> vecDir[i].second;
	}

	int iAns = 0;
	if (vecDir[0].first != 0 && vecDir[0].first == vecDir[0].second)
	{
		++iAns;
	}

	for (int i = 1; i < iT; ++i)
	{
		if (vecDir[i].first != 0 && vecDir[i].first == vecDir[i].second) ++iAns;
		if (vecDir[i].first != 0 && vecDir[i].first == vecDir[i - 1].first) ++iAns;
		if (vecDir[i].second != 0 && vecDir[i].second == vecDir[i - 1].second) ++iAns;
	}

	cout << iAns << "\n";
	return 0;
}
