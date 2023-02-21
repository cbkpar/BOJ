#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	int iSum = 0;
	while (iN--)
	{
		int iHour, iMinute;
		cin >> iHour >> iMinute;
		iSum += iHour * 60 + iMinute;
	}
	int iMax = (iSum + 239) / 240;
	int iCost = iMax * 1090;
	for (int i = 0; i < iMax; ++i)
	{
		int iTemp = 1090 * i + 915 * ((iSum - i * 240 + 179) / 180);
		if (iTemp < iCost)
		{
			iCost = iTemp;
		}
	}

	printf("%d.%02d", (iCost / 100), (iCost % 100));
	return 0;
}
