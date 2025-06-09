#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int vecCount[100][100] = { 0, };
int vecTime[100][100] = { 0, };

int TimeToInt(string time)
{
	int iRet = 0;
	iRet += (time[4] - '0');
	iRet += (time[3] - '0') * 10;
	iRet += (time[1] - '0') * 60;
	iRet += (time[0] - '0') * 600;
	return iRet;
}

int CalcDiff(string start, string end)
{
	return TimeToInt(end) - TimeToInt(start);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;
	iM /= 7;

	int iIndex = 0;
	map<string, int> mapName;

	for (int i = 0;i < iN;++i)
	{
		string strName, strStart, strEnd;
		int iDay;
		cin >> strName >> iDay >> strStart >> strEnd;
		--iDay;

		if (mapName.find(strName) == mapName.end())
		{
			mapName[strName] = iIndex++;
		}

		int iNow = mapName[strName];
		int iWeek = iDay / 7;
		vecCount[iNow][iWeek] += 1;
		vecTime[iNow][iWeek] += CalcDiff(strStart, strEnd);
	}

	vector<string> vecAns;
	for (auto iter : mapName)
	{
		int iNow = iter.second;
		bool bPossible = true;
		for (int i = 0;i < iM;++i)
		{
			if (vecCount[iNow][i] < 5) bPossible = false;
			if (vecTime[iNow][i] < 3600) bPossible = false;
		}
		if (bPossible)
		{
			vecAns.push_back(iter.first);
		}
	}

	int iSize = vecAns.size();
	if (iSize == 0)
	{
		cout << "-1" << "\n";
	}
	else
	{
		for (int i = 0;i < iSize;++i)
		{
			cout << vecAns[i] << "\n";
		}
	}
	return 0;
}
