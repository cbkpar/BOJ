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

	for (int i = 0;i < iN;++i)
	{
		int iX, iY, iA, iB;
		cin >> iX >> iY >> iA >> iB;

		int iDist = iY - iX;
		int iDiff = iB + iA;
		if (iDist % iDiff == 0)
		{
			cout << (iDist / iDiff) << "\n";
		}
		else
		{
			cout << "-1" << "\n";
		}
	}
	return 0;
}
