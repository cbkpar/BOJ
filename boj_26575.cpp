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
		double dD, dF, dP;
		cin >> dD >> dF >> dP;

		double dProduct = dD * dF * dP;
		printf("$%.02lf\n", dProduct);
	}
	return 0;
}
