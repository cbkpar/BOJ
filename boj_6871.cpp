#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iDay, iEven, iWeek;
	cin >> iDay >> iEven >> iWeek;

	int iA = 0;
	int iB = 0;

	if (iDay > 100) iA += (iDay - 100) * 25;
	if (iDay > 250) iB += (iDay - 250) * 45;

	iA += iEven * 15;
	iB += iEven * 35;

	iA += iWeek * 20;
	iB += iWeek * 25;

	printf("Plan A costs %.02f\n", (double)(iA / 100.0));
	printf("Plan B costs %.02f\n", (double)(iB / 100.0));

	if (iA > iB)
	{
		printf("Plan B is cheapest.\n");
	}
	else if (iB > iA)
	{
		printf("Plan A is cheapest.\n");
	}
	else
	{
		printf("Plan A and B are the same price.\n");
	}
	return 0;
}
