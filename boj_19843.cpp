#include <iostream>
#include <string>

using namespace std;

int CalcHour(string str, int iHour)
{
	if (str == "Mon") iHour += 0;
	if (str == "Tue") iHour += 24;
	if (str == "Wed") iHour += 48;
	if (str == "Thu") iHour += 72;
	if (str == "Fri") iHour += 96;

	return iHour;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iNeed;
	cin >> iNeed;
	int iM;
	cin >> iM;
	while (iM--)
	{
		string strStart;
		int iStart;
		string strEnd;
		int iEnd;
		cin >> strStart >> iStart >> strEnd >> iEnd;
		iNeed -= CalcHour(strEnd, iEnd) - CalcHour(strStart, iStart);
	}
	if (iNeed < 0)
	{
		iNeed = 0;
	}
	if (iNeed > 48)
	{
		cout << "-1\n";
	}
	else
	{
		cout << iNeed << "\n";
	}
	return 0;
}
