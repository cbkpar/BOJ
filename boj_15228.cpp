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

	int iAns = iN;
	for (int i = 1;i <= 14;++i)
	{
		int iTemp = 1 << i;
		int iDay = i + (iN + iTemp - 1) / iTemp;
		iAns = min(iAns, iDay);
	}

	cout << iAns << "\n";
	return 0;
}
