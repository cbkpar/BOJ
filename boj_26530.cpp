#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

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
		int iN;
		cin >> iN;

		double dSum = 0.0;

		while (iN--)
		{
			string strName;
			cin >> strName;
			double dCount, dCost;
			cin >> dCount >> dCost;
			dSum += dCount * dCost;
		}
		printf("$%.02lf\n", dSum);
	}

	return 0;
}
