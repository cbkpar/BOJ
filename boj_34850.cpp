#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	long long lX, lY, lP, lA, lB;
	cin >> lX >> lY >> lP >> lA >> lB;

	long long lPrice = lP + lB * (lY - 1);
	long long lAns = lPrice * lX - ((lX - 1) * (lX)*lA) / 2;
	cout << lAns << "\n";

	return 0;
}
