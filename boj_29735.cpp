#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int CalcTime(string strTime)
{
	int iHour = (strTime[0] - '0') * 10 + (strTime[1] - '0');
	int iMinute = (strTime[3] - '0') * 10 + (strTime[4] - '0');
	return iHour * 60 + iMinute;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string strFirst, strSecond;
	cin >> strFirst >> strSecond;

	int iStart = CalcTime(strFirst);
	int iEnd = CalcTime(strSecond);

	int iN, iT;
	cin >> iN >> iT;

	int iDay = 0;
	int iTime = iStart;

	++iN;
	while (iN-- > 0)
	{
		if (iTime + iT >= iEnd)
		{
			++iDay;
			iTime = iStart;
		}
		iTime += iT;
	}

	cout << iDay << "\n";
	printf("%02d:%02d\n", iTime / 60, iTime % 60);
	return 0;
}
