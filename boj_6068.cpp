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

	vector<pair<int, int>> vecWork(iN, { 0,0 });
	for (int i = 0; i < iN; ++i)
	{
		cin >> vecWork[i].second >> vecWork[i].first;
	}

	sort(vecWork.begin(), vecWork.end(), greater<>());

	int iAns = vecWork[0].first;
	for (int i = 0; i < iN; ++i)
	{
		iAns -= vecWork[i].second;
		if (iAns > vecWork[i].first - vecWork[i].second)
		{
			iAns = vecWork[i].first - vecWork[i].second;
		}
	}
	if (iAns < 0)
	{
		cout << "-1\n";
	}
	else
	{
		cout << iAns << "\n";
	}

	return 0;
}
