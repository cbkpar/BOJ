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
	vector<pair<int, int>> vecStudent(iN, { 0,0 });

	for (int i = 0; i < iN; ++i)
	{
		cin >> vecStudent[i].first >> vecStudent[i].second;
	}
	sort(vecStudent.begin(), vecStudent.end(), [](const pair<int, int>& o1, const pair<int, int>& o2)->bool
		{
			if (o1.first == o2.first) return o1.second < o2.second;
			return o1.first > o2.first;
		});

	int iAns = 0;
	for (int i = 5; i < iN; ++i)
	{
		if (vecStudent[i].first == vecStudent[4].first)
		{
			++iAns;
		}
	}
	cout << iAns << "\n";
	return 0;
}
