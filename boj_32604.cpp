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

	vector<pair<int, int>> vecScore(iN, { 0,0 });
	for (int i = 0;i < iN;++i)
	{
		cin >> vecScore[i].first >> vecScore[i].second;
	}

	bool bPossible = true;

	for (int i = 1;i < iN;++i)
	{
		if (vecScore[i].first < vecScore[i - 1].first) bPossible = false;
		if (vecScore[i].second < vecScore[i - 1].second) bPossible = false;
	}

	if (bPossible)
	{
		cout << "yes" << "\n";
	}
	else
	{
		cout << "no" << "\n";
	}
	return 0;
}
