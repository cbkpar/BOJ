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
	vector<pair<int, long long>> vecPeople(iN, { 0,0 });
	for (int i = 0; i < iN; ++i)
	{
		cin >> vecPeople[i].first;
		long long lA, lB, lC;
		cin >> lA >> lB >> lC;
		vecPeople[i].second = lA * lB * lC * 1000000000 + (lA + lB + lC);
	}

	sort(vecPeople.begin(), vecPeople.end(), [](const pair<int, long long>& o1, const pair<int, long long>& o2)->bool
		{
			if (o1.second != o2.second) return o1.second < o2.second;
			return o1.first < o2.first;
		});

	cout << vecPeople[0].first << " ";
	cout << vecPeople[1].first << " ";
	cout << vecPeople[2].first << "\n";
	return 0;
}
