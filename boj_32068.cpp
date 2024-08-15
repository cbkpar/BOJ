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
		long long lL, lR, lS;
		cin >> lL >> lR >> lS;

		long long lAns = min((lR - lS) * 2, (lS - lL) * 2 + 1);
		cout << lAns << "\n";
	}
	return 0;
}
