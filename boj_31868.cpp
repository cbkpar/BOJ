#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long lN, lK;
	cin >> lN >> lK;

	long long lAns = lK / (1 << (lN - 1));
	cout << lAns << "\n";
	return 0;
}
