#include <iostream>

using namespace std;

int arrNumber[100] = { 0, };

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
		for (int i = 0; i < iN; ++i)
		{
			cin >> arrNumber[i];
		}
		int iIndex = 0;
		int iCount = 0;
		int iMax = 2440;
		int iK;
		cin >> iK;
		while (iK--)
		{
			int iNumber, iHour, iMinute;
			cin >> iNumber >> iHour >> iMinute;
			for (int i = 0; i < iN; ++i)
			{
				if (arrNumber[i] == iNumber)
				{
					int iTime = iHour * 60 + iMinute;
					if (iHour != -1 && iMinute != -1 && iTime <= 360)
					{
						++iCount;
						if (iTime < iMax)
						{
							iMax = iTime;
							iIndex = i;
						}
					}
				}
			}
		}
		cout << arrNumber[iIndex] << " " << iCount << "\n";
	}
	return 0;
}
