#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	iN -= 1;
	if (iN % 3 == 0) cout << "U" << "\n";
	if (iN % 3 == 1) cout << "O" << "\n";
	if (iN % 3 == 2) cout << "S" << "\n";

	return 0;
}
