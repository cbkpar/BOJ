#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	while (iT--)
	{
		int m, xs, ys, xf, yf;
		cin >> m >> xs >> ys >> xf >> yf;
		if (abs(xf - xs) + abs(yf - ys) <= m)
		{
			cout << "First 1\n";
		}
		else
		{
			cout << "Infinity\n";
		}
	}

	return 0;
}
