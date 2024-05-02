#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iC, iS;
	cin >> iN >> iC >> iS;
	--iS;

	int iNow = 0;
	int iAns = 0;
	if (iS == 0) ++iAns;
	while (iC--)
	{
		int iDir;
		cin >> iDir;
		iNow = (iNow + iN + iDir) % iN;
		if (iNow == iS) ++iAns;
	}

	cout << iAns << "\n";
	return 0;
}
