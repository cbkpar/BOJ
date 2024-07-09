#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	double dX, dY;
	cin >> dX >> dY;

	double dAns = (dX) / (100.0 - dX) * (100.0 - dY) / (dY);
	cout.precision(30);
	cout << fixed << dAns << "\n";
	return 0;
}
