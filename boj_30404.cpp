#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iK;
	cin >> iN >> iK;

	int iMax = -1;
	int iAns = 0;
	for (int i = 0; i < iN; ++i)
	{
		int iX;
		cin >> iX;
		if (iX > iMax)
		{
			++iAns;
			iMax = iX + iK;
		}
	}
	cout << iAns << "\n";
	return 0;
}
