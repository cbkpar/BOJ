#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long lW, lS;
	cin >> lW >> lS;

	long long lN = (lS * (lS + 1)) / 2;
	long long lDiff = lW - lN * 29260;
	long long lAns = lDiff / 110;

	cout << lAns << "\n";
	return 0;
}
