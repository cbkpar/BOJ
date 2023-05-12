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

	int iBefore = 0;
	int iNow = 1;
	while (iN > 0)
	{
		iN -= iNow;
		int iNext = iBefore + iNow;
		iBefore = iNow;
		iNow = iNext;
		++iAns;
	}

	cout << iAns << "\n";
	
	return 0;
}
