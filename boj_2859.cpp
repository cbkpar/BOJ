#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string ArrDay[7] = { "Saturday","Sunday","Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };

int DateToInt(string strDate)
{
	int iHour = (strDate[0] - '0') * 10 + (strDate[1] - '0');
	int iMinute = (strDate[3] - '0') * 10 + (strDate[4] - '0');
	return iHour * 60 + iMinute;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iS1, iS2, iE1, iE2;
	string strDate;

	cin >> strDate;
	iS1 = DateToInt(strDate);
	cin >> strDate;
	iS2 = DateToInt(strDate);
	cin >> strDate;
	iE1 = DateToInt(strDate);
	cin >> strDate;
	iE2 = DateToInt(strDate);

	int iAns = -1;

	for (int i = 0; i < 10080; ++i)
	{
		int iTime = iS1 + iE1 * i;
		if (iTime < iS2) continue;
		if ((iTime - iS2) % iE2 == 0)
		{
			iAns = iTime % 10080;
			break;
		}
	}

	if (iAns == -1)
	{
		cout << "Never\n";
	}
	else
	{
		int iDay = iAns / 1440;
		int iHour = (iAns % 1440) / 60;
		int iMinute = (iAns % 60);

		cout << ArrDay[iDay] << "\n";
		cout.width(2);
		cout.fill('0');
		cout << iHour << ":";
		cout.width(2);
		cout.fill('0');
		cout << iMinute << "\n";
	}

	return 0;
}
