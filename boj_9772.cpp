#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true)
	{
		double dX, dY;
		cin >> dX >> dY;
		
		if (dX == 0 || dY == 0)
		{
			cout << "AXIS\n";
		}
		else
		{
			if (dX > 0 && dY > 0) cout << "Q1\n";
			if (dX < 0 && dY > 0) cout << "Q2\n";
			if (dX < 0 && dY < 0) cout << "Q3\n";
			if (dX > 0 && dY < 0) cout << "Q4\n";
		}
		if (dX == 0 && dY == 0) break;
	}
	return 0;
}
