#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true)
	{
		int iA, iB;
		cin >> iA >> iB;
		if (iA == 0 && iB == 0) break;

		double dAns = 100000;
		for (int i = 0; i <= iA; ++i)
		{
			double dCost = sqrt((i * i) + (iA - i) * (iA - i));
			dAns = min(dAns, abs(dCost - iB));
		}

		cout << fixed;
		cout.precision(30);
		cout << dAns << "\n";
	}

	return 0;
}
