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

	long long lAns = 10000000000L;
	for (int i = 0;i < iN;++i)
	{
		long long lTime;
		int iType;
		cin >> lTime >> iType;
		if (iType != 0) continue;
		lAns = min(lAns, lTime);
	}

	if (lAns == 10000000000L)
	{
		cout << "-1" << "\n";
	}
	else
	{
		cout << lAns << "\n";
	}

	return 0;
}
