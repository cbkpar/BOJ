#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int CalcTime(string strTime)
{
	int iRet = 0;
	iRet += (strTime[0] - '0') * 600;
	iRet += (strTime[1] - '0') * 60;
	iRet += (strTime[3] - '0') * 10;
	iRet += (strTime[4] - '0') * 1;
	return iRet;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	string strStart, strEnd;
	cin >> strStart >> strEnd;

	int iStart = CalcTime(strStart);
	int iEnd = CalcTime(strEnd);

	int iNext = (iEnd - iStart + 1440);
	printf("%02d:%02d\n", (iNext / 60), (iNext % 60));

	return 0;
}
