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

	if (iN == 1)
	{
		cout << "0\n";
		return 0;
	}

	int iX, iY;
	cin >> iX >> iY;

	int iAns = 0;
	if (iX == 1 || iX == iN)
	{
		iAns += 1;
	}
	else
	{
		iAns += 2;
	}
	if (iY == 1 || iY == iN)
	{
		iAns += 1;
	}
	else
	{
		iAns += 2;
	}
	cout << iAns << "\n";
	return 0;
}
