#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	double P1, P2, P3;
	double C1, C2, C3;
	cin >> P1 >> P2 >> P3;
	cin >> C1 >> C2 >> C3;

	if (P1 < P2) swap(P1, P2);
	if (P1 < P3) swap(P1, P3);
	if (P2 < P3) swap(P2, P3);
	if (C2 < C3) swap(C2, C3);

	double dSum = P1 + P2 + P3;
	double dCost1 = dSum * C1 / 100.0;
	double dCost2 = (P1 * C2 + P2 * C3) / 100.0;
	if (dCost1 > dCost2)
	{
		printf("one %.02lf\n", dCost1);
	}
	else
	{
		printf("two %.02lf\n", dCost2);
	}
	return 0;
}
