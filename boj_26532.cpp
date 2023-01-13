#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long lA, lB;
	cin >> lA >> lB;
	long long lM = lA * lB;
	lM += 24199;
	cout << (lM / 24200) << "\n";

	return 0;
}
