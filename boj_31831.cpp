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

	int iAns = 0;
	int iNow = 0;

	for (int i = 0;i < iN;++i)
	{
		int iAmount;
		cin >> iAmount;

		iNow += iAmount;
		if (iNow >= iM)
		{
			++iAns;
		}

		if (iNow < 0)
		{
			iNow = 0;
		}
	}


	cout << iAns << "\n";
	return 0;
}
