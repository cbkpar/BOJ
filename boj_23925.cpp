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
	for (int t = 1;t <= iT;++t)
	{
		long long lS, lK, lN;
		cin >> lS >> lK >> lN;

		long long lAns = lS + min((lK - lN) * 2, lK);
		cout << "Case #" << t << ": " << lAns << "\n";
	}

	return 0;
}
