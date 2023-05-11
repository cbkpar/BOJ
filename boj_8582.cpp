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
	vector<int> vecNum(iN, 0);
	vector<pair<int, int>> vecAns(iN, { 0,0 });
	for (int i = 0; i < iN; ++i)
	{
		cin >> vecNum[i];
	}
	vecAns[0].first = vecNum[0];
	vecAns[iN - 1].second = vecNum[iN - 1];
	for (int i = 1; i < iN; ++i)
	{
		vecAns[i].first = max(vecAns[i - 1].first, vecNum[i]);
	}
	for (int i = iN - 2; i >= 0; --i)
	{
		vecAns[i].second = max(vecAns[i + 1].second, vecNum[i]);
	}
	for (int i = 0; i < iN; ++i)
	{
		cout << vecAns[i].first << " " << vecAns[i].second << "\n";
	}
	return 0;
}
