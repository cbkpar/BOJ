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
	std::cout.tie(NULL);

	string strTimeA, strTimeB;
	cin >> strTimeA >> strTimeB;

	int iTimeA = CalcTime(strTimeA);
	int iTimeB = CalcTime(strTimeB);

	int iH = 0;
	int iM = 0;
	int iS = 0;
	for (int i = iTimeA;i < iTimeB;++i)
	{
		if (i % 60 == 59) ++iS;
		if (i % 3600 == 3599) ++iM;
		if (i % 43200 == 43199) ++iH;
	}

	cout << iH << " ";
	cout << iM << " ";
	cout << iS << "\n";


	return 0;
}
