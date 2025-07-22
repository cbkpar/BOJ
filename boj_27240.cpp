#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iA, iB;
	cin >> iN >> iA >> iB;

	int iS, iT;
	cin >> iS >> iT;

	if (iS > iT) swap(iS, iT);

	if (iT <= iA || iS >= iB)
	{
		cout << "Outside" << "\n";
	}
	else if (iS > iA && iT < iB)
	{
		cout << "City" << "\n";
	}
	else
	{
		cout << "Full" << "\n";
	}
	return 0;
}
