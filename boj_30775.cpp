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

	long long lSum = 0;
	for (int i = 0;i < iM;++i)
	{
		long long lPeople;
		cin >> lPeople;
		lSum += lPeople;
	}

	if (lSum % iN == 0)
	{
		cout << lSum / iN << "\n";
	}
	else
	{
		cout << (lSum / iN) + 1 << "\n";
	}
	return 0;
}
