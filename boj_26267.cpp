#include <iostream>
#include <map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	map<int, long long> mapMoney;

	int iN;
	cin >> iN;

	for (int i = 0; i < iN; ++i)
	{
		int iX, iT;
		long long lC;
		cin >> iX >> iT >> lC;
		int iDiff = iX - iT;
		auto iter = mapMoney.find(iDiff);
		if (iter == mapMoney.end())
		{
			mapMoney.emplace(iDiff, lC);
		}
		else
		{
			mapMoney[iDiff] += lC;
		}
	}
	long long lMaxMoney = 0;
	for (auto iter : mapMoney)
	{
		if (iter.second > lMaxMoney)
		{
			lMaxMoney = iter.second;
		}
	}
	cout << lMaxMoney << "\n";
	return 0;
}
