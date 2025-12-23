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

	int iAns = 0;
	int iBefore = -1;
	int iNow = 0;
	
	for (int i = 0;i < iN;++i)
	{
		int iNum;
		cin >> iNum;

		if (iNum > iBefore)
		{
			++iNow;
		}
		else
		{
			iNow = 1;
		}
		iAns = max(iAns, iNow);
		iBefore = iNum;
	}

	cout << iAns << "\n";
	return 0;
}
