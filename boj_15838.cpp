#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iTestCase = 0;
	while (true)
	{
		int iDay;
		cin >> iDay;
		if (iDay == 0) break;

		++iTestCase;
		double dSum = 0;
		while (iDay--)
		{
			double dChicken, dBeef, dLamb, dNasi;
			cin >> dChicken >> dBeef >> dLamb >> dNasi;

			dSum += dChicken * 0.8;
			dSum += dBeef * 1.0;
			dSum += dLamb * 1.2;
			dSum += dNasi * 0.8;

			dSum -= dChicken * 7.5 / 85.0;
			dSum -= dBeef * 24.0 / 85.0;
			dSum -= dLamb * 32.0 / 85.0;
			dSum -= dNasi * 0.2;

			dSum -= (dChicken + dBeef + dLamb) * 8.0 / 85.0;
		}
		printf("Case #%d: RM%.02f\n", iTestCase, dSum);
	}
	return 0;
}
