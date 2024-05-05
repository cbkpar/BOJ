#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iA, iB, iC, iD;
	cin >> iA >> iB >> iC >> iD;
	if (iA > iB) swap(iA, iB);
	if (iC > iD) swap(iC, iD);

	int iAns = (iB - iA + 1) + (iD - iC + 1);
	int iTemp = max(iB, iD) - min(iA, iC) + 1;
	iAns = min(iAns, iTemp);

	cout << iAns << "\n";
	return 0;
}
