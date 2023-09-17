#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iW, iH;
	cin >> iW >> iH;

	int iArea = iW * iH;
	cout << iArea / 2 << "." << (iArea % 2 == 1 ? "5" : "0") << "\n";
	return 0;
}
