#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iW, iN;
	cin >> iW >> iN;

	int iAns = iW * 5280 / iN;

	cout << iAns << "\n";
	return 0;
}
