#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	while (iN--)
	{
		double dX, dY;
		cin >> dX >> dY;
		if ((dX - 1.0) * (dY - 1.0) > 1.0)
		{
			cout << "TAK" << "\n";
		}
		else
		{
			cout << "NIE" << "\n";
		}
	}

	return 0;
}
