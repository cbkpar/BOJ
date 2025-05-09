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

	vector<pair<int, int>> vecNum(iN, { 0,0 });
	for (int i = 0; i < iN; ++i)
	{
		int iNum;
		cin >> iNum;

		vecNum[i].first = iNum;
		vecNum[i].second = i;
	}

	sort(vecNum.begin(), vecNum.end());

	int iAns = 1;
	for (int i = 0; i < iN; ++i)
	{
		if (vecNum[i].second > i)
		{
			iAns = max(iAns, vecNum[i].second - i + 1);
		}
	}

	cout << iAns << "\n";
	return 0;
}
