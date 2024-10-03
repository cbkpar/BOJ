#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int DateToTime(string strTime)
{
	int iRet = 0;
	iRet += (strTime[0] - '0') * 1000;
	iRet += (strTime[1] - '0') * 100;
	iRet += (strTime[3] - '0') * 10;
	iRet += (strTime[4] - '0') * 1;
	return iRet;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int iN;
	cin >> iN;

	int iTeacher = 0;

	vector<int> vecTime;
	for (int i = 0;i < iN + 1;++i)
	{
		string strTime, strType;
		cin >> strTime >> strType;
		
		int iTime = DateToTime(strTime);
		if (strType == "student")
		{
			vecTime.push_back(iTime);
		}
		else
		{
			iTeacher = iTime;
		}
	}
	
	string strLimit;
	cin >> strLimit;
	int iLimit = DateToTime(strLimit);

	int iAns = 0;
	for (int i = 0;i < iN;++i)
	{
		if (vecTime[i] >= iTeacher && vecTime[i] >= iLimit)
		{
			++iAns;
		}
	}

	cout << iAns << "\n";
	return 0;
}
