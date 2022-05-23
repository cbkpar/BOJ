#include <iostream>

using namespace std;

int g_day[13] = { 0, 31,28,31,30,31,30,31,31,30,31,30,31 };

int main()
{
	while (true)
	{
		int iDay, iMonth, iYear;
		cin >> iDay >> iMonth >> iYear;
		if (0 == iDay)
		{
			break;
		}
		int iTotal = 0;
		if (0 == iYear % 4)
		{
			if (0 != iYear % 400 && 0 == iYear % 100)
			{

				g_day[2] = 28;
			}
			else
			{
				g_day[2] = 29;
			}
		}
		else
		{
			g_day[2] = 28;
		}
		for (int i = 0; i < iMonth; ++i)
		{
			iTotal += g_day[i];
		}
		iTotal += iDay;
		cout << iTotal << endl;
	}
	return 0;
}
