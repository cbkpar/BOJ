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

	vector<vector<int>> vecFolder(iN + iM + 1, vector<int>());
	vector<set<int>> vecFile(iN + iM + 1, set<int>());
	vector<set<int>> vecTotalFile(iN + iM + 1, set<int>());
	vector<int> vecParent(iN + iM + 1, -1);
	vector<int> vecCount(iN + iM + 1, 0);

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
			vecCount[iB] = -1;
		}
		else
		{
			vecFolder[iA].push_back(iB);
			vecParent[iB] = iA;
			++vecCount[iA];
		}
	}

	int iK;
	cin >> iK;
	while (iK--)
	{
		string strPathA, strPathB;
		cin >> strPathA >> strPathB;

		string strFolderA = "";
		int iLen = strPathA.length();
		for (int i = iLen - 1;i >= 0;--i)
		{
			if (strPathA[i] == '/') break;
			strFolderA = strPathA[i] + strFolderA;
		}
		int iA = mapName[strFolderA];

		string strFolderB = "";
		iLen = strPathB.length();
		for (int i = iLen - 1;i >= 0;--i)
		{
			if (strPathB[i] == '/') break;
			strFolderB = strPathB[i] + strFolderB;
		}
		int iB = mapName[strFolderB];

		for (int iFolder : vecFolder[iA])
		{
			if (vecCount[iFolder] == -1) continue;
			++vecCount[iB];
			vecParent[iFolder] = iB;
			vecFolder[iB].push_back(iFolder);
		}

		if (vecParent[iA] != -1)
		{
			--vecCount[vecParent[iA]];
			vecParent[iA] = -1;
			vecCount[iA] = -1;
		}

		for (int iFile : vecFile[iA])
		{
			vecFile[iB].insert(iFile);
			vecTotalFile[iB].insert(iFile);
		}
	}

	vector<int> vecTotalCount(iN + iM + 1, 0);
	queue<int> qNum;
	for (int i = 0;i < iN + iM + 1;++i)
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
