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

	int iT;
	cin >> iT;
	for (int t = 1; t <= iT; ++t)
	{
		long long lR, lA, lB;
		cin >> lR >> lA >> lB;
		cout << "Case #" << t << ": ";

		double dAns = 0;
		while (lR >= 1)
		{
			dAns += lR * lR * (1 + lA * lA);
			lR = (lR * lA) / lB;
		}
		dAns *= 3.14159265358979323846;

		cout << fixed;
		cout.precision(30);
		cout << dAns << "\n";
	}

	return 0;
}
