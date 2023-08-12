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

	int iAns = 200;
	while (iN--)
	{
		int iA, iB;
		cin >> iA >> iB;
		iAns = min(iAns, iA + iB);
	}

	cout << iAns << "\n";
	return 0;
}
