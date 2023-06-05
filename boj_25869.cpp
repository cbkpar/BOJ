#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iW, iH, iD;
	cin >> iW >> iH >> iD;

	iW = max(0, iW - 2 * iD);
	iH = max(0, iH - 2 * iD);

	cout << (iW * iH) << "\n";
	return 0;
}
