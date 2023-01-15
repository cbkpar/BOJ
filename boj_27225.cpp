#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iA, iB;
	cin >> iA >> iB;

	int iSum = (iA < iB ? iA : iB) * 2 + (((iA + iB) % 2 == 1) ? 1 : 0);
	cout << iSum << "\n";
	return 0;
}
