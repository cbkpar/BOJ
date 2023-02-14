#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long lA, lB, lC, lD;
	cin >> lA >> lB >> lC >> lD;

	cout << (lC + lD) / (lA - lB) << "\n";

	return 0;
}
