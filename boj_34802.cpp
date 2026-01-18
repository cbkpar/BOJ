#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int CalcTime(string strTime)
{
	int iRet = 0;
	iRet += (strTime[0] - '0') * 36000;
	iRet += (strTime[1] - '0') * 3600;
	iRet += (strTime[3] - '0') * 600;
	iRet += (strTime[4] - '0') * 60;
	iRet += (strTime[6] - '0') * 10;
	iRet += (strTime[7] - '0') * 1;
	return iRet;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string strTime1, strTime2;
	cin >> strTime1 >> strTime2;

	int iTime1 = CalcTime(strTime1);
	int iTime2 = CalcTime(strTime2);

	int iT, iK;
	cin >> iT >> iK;

	int iLimit = iTime2 - iTime1;
	if (iLimit < 0)
	{
		cout << "0";
		return 0;
	}

	if (iLimit >= (iT / 100) * (100 - iK))
	{
		cout << "1";
	}
	else
	{
		cout << "0";
	}
	return 0;
}
