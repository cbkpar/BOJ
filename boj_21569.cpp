#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iA, iB;
	cin >> iA >> iB;
	cout << ((max(iA, iB) + 1) / 2) << " " << min(iA, iB) << "\n";
	return 0;
}
