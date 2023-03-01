#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long lN;
	cin >> lN;
	cout << ((lN) * (lN - 1) * (lN - 2) / 6) << "\n3\n";
	return 0;
}
