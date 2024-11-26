#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int UTCtoTime(string strTime)
{
	bool bMinus = false;
	if (strTime[3] == '-') bMinus = true;
	int iTime = 0;
	int iLen = strTime.length();
	for (int i = 4;i < iLen;++i)
	{
		if (strTime[i] == '.')
		{
			iTime += 30;
			break;
		}
		else
		{
			iTime *= 10;
			iTime += (strTime[i] - '0') * 60;
		}
	}
	if (bMinus) iTime *= -1;
	return iTime;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	string strTime;
	cin >> strTime;

	int iNow = ((strTime[0] - '0') * 10 + strTime[1] - '0') * 60;
	iNow += ((strTime[3] - '0') * 10 + strTime[4] - '0');

	string strNow;
	cin >> strNow;

	int iNowUTC = UTCtoTime(strNow);
	for (int i = 0;i < iN;++i)
	{
		string strNext;
		cin >> strNext;

		int iNextUTC = UTCtoTime(strNext);
		int iNext = (iNow + iNextUTC - iNowUTC + 1440) % 1440;
		printf("%02d:%02d\n", iNext / 60, iNext % 60);
	}

	return 0;
}
