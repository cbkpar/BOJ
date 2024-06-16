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
	for (int t = 1; t <= iT; ++t)
	{
		int iN, iM;
		cin >> iN >> iM;

		int iAns = max(0, iM - iN + 1);
		cout << "Case " << t << ": " << iAns << "\n";
	}
	return 0;
}
