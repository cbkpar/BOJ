#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iX1, iY1;
	cin >> iX1 >> iY1;

	int iX2, iY2;
	cin >> iX2 >> iY2;

	int iT;
	cin >> iT;

	int iDist = abs(iX1 - iX2) + abs(iY1 - iY2);

	if (iT < iDist)
	{
		cout << "N" << "\n";
	}
	else
	{
		if (iDist % 2 == iT % 2)
		{
			cout << "Y" << "\n";
		}
		else
		{
			cout << "N" << "\n";
		}
	}

	return 0;
}
