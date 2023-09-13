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

	long long lMax = 0;
	long long lSum = 0;

	for (int i = 0; i < iN; ++i)
	{
		long long lNum;
		cin >> lNum;

		lSum += lNum;
		lMax = max(lMax, lNum);
	}

	long long lAns = lSum + lMax * (iN - 2);
	cout << lAns << "\n";
	return 0;
}
