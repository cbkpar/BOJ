#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;

	int iAns = iN + iM;
	iAns = min(iAns, iN * 2 + 1);
	iAns = min(iAns, iM * 2 + 1);

	cout << iAns << "\n";
	return 0;
}
