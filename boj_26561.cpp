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
		long long lP, lT;
		cin >> lP >> lT;
		lP += lT / 4;
		lP -= lT / 7;
		cout << lP << "\n";
	}

	return 0;
}
