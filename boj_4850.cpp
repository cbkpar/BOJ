#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long lN, lW, lD, lT;
	while (cin >> lN >> lW >> lD >> lT)
	{
		long long lTotal = (lN * (lN - 1) / 2) * lW;
		long long lDiff = lTotal - lT;
		if (lDiff == 0)
		{
			cout << lN << "\n";
		}
		else
		{
			cout << lDiff / lD << "\n";
		}
	}
	return 0;
}
