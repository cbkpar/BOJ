#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	while (iT--)
	{
		int iK, iA, iB;
		cin >> iK >> iA >> iB;
		int iAns = min(max(iK, iB + 2) - iA, max(iK, iA + 2) - iB);
		if (iAns < 0) iAns = 0;
		cout << iAns << "\n";
	}
	return 0;
}
