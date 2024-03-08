#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM, iK;
	cin >> iN >> iM >> iK;

	int iDiff = iK - iM;
	int iAns = (iN + iDiff - 1) / iDiff;

	cout << iAns << "\n";
	return 0;
}
