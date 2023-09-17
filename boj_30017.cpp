#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iA, iB;
	cin >> iA >> iB;

	if (iA > iB + 1) iA = iB + 1;
	if (iB > iA - 1) iB = iA - 1;

	cout << (iA + iB) << "\n";
	return 0;
}
