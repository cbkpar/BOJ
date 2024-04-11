#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iX, iY;
	cin >> iX >> iY;

	int iB = (iY - iX * 2) / 2;
	int iA = iX - iB;

	cout << iA << " " << iB << "\n";
	return 0;
}
