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
		double dP, dQ;
		cin >> dP >> dQ;

		printf("f = %.01lf\n", (dP * dQ) / (dP + dQ));
	}
	return 0;
}
