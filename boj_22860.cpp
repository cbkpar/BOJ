#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;

	int iIndex = 0;
	map<string, int> mapName;

	vector<set<int>> vecFile(iN + iM, set<int>());
	vector<set<int>> vecTotalFile(iN + iM, set<int>());
	vector<int> vecParent(iN + iM, -1);
	vector<int> vecCount(iN + iM, 0);

	for (int i = 0;i < iN + iM;++i)
	{
		string strParent, strChild;
		int iType;
		cin >> strParent >> strChild >> iType;

		if (mapName.find(strParent) == mapName.end())
		{
			mapName.insert({ strParent, iIndex++ });
		}

		if (mapName.find(strChild) == mapName.end())
		{
			mapName.insert({ strChild, iIndex++ });
		}

		int iA = mapName[strParent];
		int iB = mapName[strChild];

		if (iType == 0)
		{
			vecFile[iA].insert(iB);
			vecTotalFile[iA].insert(iB);
		}
		else
		{
			vecParent[iB] = iA;
			++vecCount[iA];
		}
	}

	vector<int> vecTotalCount(iN + iM, 0);

	queue<int> qNum;
	for (int i = 0;i < iN + iM;++i)
	{
		if (vecCount[i] == 0)
		{
			qNum.push(i);
		}
	}

	while (!qNum.empty())
	{
		int iNum = qNum.front();
		qNum.pop();

		vecTotalCount[iNum] += vecFile[iNum].size();
		if (vecParent[iNum] != -1)
		{
			for (int iFile : vecTotalFile[iNum])
			{
				vecTotalFile[vecParent[iNum]].insert(iFile);
			}
			vecTotalCount[vecParent[iNum]] += vecTotalCount[iNum];
			if (--vecCount[vecParent[iNum]] == 0)
			{
				qNum.push(vecParent[iNum]);
			}
		}
	}

	int iQ;
	cin >> iQ;
	while (iQ--)
	{
		string strPath;
		cin >> strPath;

		string strFolder = "";
		int iLen = strPath.length();
		for (int i = iLen - 1;i >= 0;--i)
		{
			if (strPath[i] == '/') break;
			strFolder = strPath[i] + strFolder;
		}

		int iNum = mapName[strFolder];
		cout << vecTotalFile[iNum].size() << " " << vecTotalCount[iNum] << "\n";
	}
	return 0;
}
