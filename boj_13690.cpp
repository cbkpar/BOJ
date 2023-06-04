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
		double dReward;
		int iM, iN;
		cin >> dReward >> iM >> iN;
		if (dReward == 0.0 && iM == 0 && iN == 0) break;

		if (iM % 10000 == iN % 10000)
		{
			printf("%.02f\n", dReward * 3000.0);
		}
		else if (iM % 1000 == iN % 1000)
		{
			printf("%.02f\n", dReward * 500.0);
		}
		else if (iM % 100 == iN % 100)
		{
			printf("%.02f\n", dReward * 50.0);
		}
		else if (((iM + 99) % 100) / 4 == ((iN + 99) % 100) / 4)
		{
			printf("%.02f\n", dReward * 16.0);
		}
		else
		{
			printf("%.02f\n", dReward * 0.0);
		}
	}
	return 0;
}
