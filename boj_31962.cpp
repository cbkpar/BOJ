#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iX;
	cin >> iN >> iX;

	int iAns = -1;

	for (int i = 0;i < iN;++i)
	{
		int iS, iT;
		cin >> iS >> iT;

		if (iS + iT <= iX)
		{
			iAns = max(iAns, iS);
		}
	}

	cout << iAns << "\n";
	return 0;
}
