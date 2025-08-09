#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iS, iC, iO, iN;
	cin >> iS >> iC >> iO >> iN;

	iS += iN;
	iC += iO * 2;

	int iAns = min(iS/3, iC/6);
	cout << iAns << "\n";

	return 0;
}
