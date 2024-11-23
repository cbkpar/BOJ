#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iA, iB, iP;
	cin >> iA >> iB >> iP;

	cout << iP * ((iA * iB + 11) / 12) << "\n";

	return 0;
}
