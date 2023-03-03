#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iS, iK;
	cin >> iS >> iK;
	long long lAns = 0;

	for (int i = 1; i <= iK; ++i)
	{
		int iCount = iK / i - (iS - 1) / i;
		if (i % 2 == 0)
		{
			lAns += iCount;
		}
		else
		{
			lAns -= iCount;
		}
	}
	cout << lAns << "\n";

	return 0;
}
