#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT1, iE1, iF1;
	int iT2, iE2, iF2;

	cin >> iT1 >> iE1 >> iF1;
	cin >> iT2 >> iE2 >> iF2;

	int iSum1 = iT1 * 3 + iE1 * 20 + iF1 * 120;
	int iSum2 = iT2 * 3 + iE2 * 20 + iF2 * 120;

	if (iSum1 > iSum2)
	{
		cout << "Max" << "\n";
	}
	else if (iSum1 == iSum2)
	{
		cout << "Draw" << "\n";
	}
	else
	{
		cout << "Mel" << "\n";
	}

	return 0;
}
