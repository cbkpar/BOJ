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

	int iACandi = 0;
	int iATotal = 0;
	int iBCandi = 0;
	int iBTotal = 0;

	while (iN-- > 0)
	{
		int iE, iA, iB;
		cin >> iE >> iA >> iB;

		if (iA > iB)
		{
			iACandi += iE;
		}
		else
		{
			iBCandi += iE;
		}
		iATotal += iA;
		iBTotal += iB;
	}

	if (iACandi > iBCandi && iATotal > iBTotal)
	{
		cout << "1" << "\n";
	}
	else if (iACandi < iBCandi && iATotal < iBTotal)
	{
		cout << "2" << "\n";
	}
	else
	{
		cout << "0" << "\n";
	}
	return 0;
}
