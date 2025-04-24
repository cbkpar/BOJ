#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;

	vector<pair<int, int>> vecNum(iN, { 0,0 });
	for (int i = 0;i < iN;++i)
	{
		vecNum[i] = { i, i +1 };
	}

	int iNow = -1;
	for (int i = 0;i < iM;++i)
	{
		int iNum;
		cin >> iNum;
		vecNum[iNum - 1].first = iNow--;
	}

	sort(vecNum.begin(), vecNum.end());
	for (int i = 0;i < iN;++i)
	{
		cout << vecNum[i].second << "\n";
	}

	return 0;
}
