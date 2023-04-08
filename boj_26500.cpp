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
		double dA, dB;
		cin >> dA >> dB;

		double dAns = abs(dB - dA);
		printf("%.1lf\n", dAns);
	}
	return 0;
}
