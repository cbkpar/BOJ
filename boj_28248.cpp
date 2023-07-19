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

	int iSum = iA * 50 - iB * 10;
	if (iA > iB) iSum += 500;

	cout << iSum << "\n";
	return 0;
}
