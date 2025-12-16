#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long lNow = 0;
	long long lAns = 0;

	int iN;
	cin >> iN;
	
	for (int i = 0;i < iN;++i)
	{
		long long lA, lB;
		cin >> lA >> lB;

		lNow -= lA;
		lNow += lB;
		lAns = max(lAns, lNow);
	}

	cout << lAns << "\n";
	return 0;
}
