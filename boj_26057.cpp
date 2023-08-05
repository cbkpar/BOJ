#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long lA, lB;
	cin >> lA >> lB;
	cout << (2 * lB - lA) << "\n";

	return 0;
}
