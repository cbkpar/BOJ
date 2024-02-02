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

	int iNow = 0;
	int iAns = 0;
	
	for (int i = 0;i < iN;++i)
	{
		int iCost;
		cin >> iCost;

		iNow += iCost;
		if (iNow <= 0)
		{
			iAns = min(iAns, iNow);
		}
	}
	cout << (-iAns) << "\n";
	return 0;
}
