#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	vector<pair<int, int>> vecPeople(iN, { 0,0 });
	for (int i = 0; i < iN; ++i)
	{
		cin >> vecPeople[i].first >> vecPeople[i].second;
	}

	sort(vecPeople.begin(), vecPeople.end(), [](const pair<int, int>& o1, const pair<int, int>& o2)->bool
		{
			if (o1.first == o2.first) return o1.second < o2.second;
			return o1.first > o2.first;
		});

	int iAns = 0;

	for (int i = 1; i < iN; ++i)
	{
		iAns = max(iAns, abs(vecPeople[i].second - vecPeople[i - 1].second));
	}

	cout << iAns << "\n";
	return 0;
}
