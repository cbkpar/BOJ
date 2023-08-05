#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iG, iP, iT;
	cin >> iG >> iP >> iT;

	int iNeedA = iG * iP;
	int iNeedB = iG + (iT * iP);

	if (iNeedA < iNeedB)
	{
		cout << "1\n";
	}
	else if (iNeedA > iNeedB)
	{
		cout << "2\n";
	}
	else
	{
		cout << "0\n";
	}

	return 0;
}
