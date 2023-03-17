#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iK, iA, iB;
	cin >> iN >> iK >> iA >> iB;
	cout << (iN + iK - 2) * iB << " " << (iN - 1) * iA << "\n";
	return 0;
}
