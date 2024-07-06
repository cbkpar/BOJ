#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

int g_iIndex = 0;
vector<vector<int>> vecNode(101, vector<int>());
vector<int> vecIndex(101, 0);
vector<bool> vecFinished(101, false);
stack<int> stNum;

int g_iSCCIndex = 0;
vector<int> vecSCCNum(101, 0);


int scc(int iNow)
{
	int iRet = vecIndex[iNow] = ++g_iIndex;
	stNum.push(iNow);

	for (int iNext : vecNode[iNow])
	{
		if (vecIndex[iNext] == 0)
		{
			iRet = min(iRet, scc(iNext));
		}
		else if (!vecFinished[iNext])
		{
			iRet = min(iRet, vecIndex[iNext]);
		}
	}

	if (iRet == vecIndex[iNow])
	{
		++g_iSCCIndex;
		while (!stNum.empty())
		{
			int iNum = stNum.top();
			stNum.pop();

			vecSCCNum[iNum] = g_iSCCIndex;
			vecFinished[iNum] = true;
			if (iNow == iNum) break;
		}
	}

	return iRet;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	vector<int> vecCost(iN, 0);
	for (int i = 0; i < iN; ++i)
	{
		cin >> vecCost[i];
	}

	for (int i = 0; i < iN; ++i)
	{
		string strNode;
		cin >> strNode;

		for (int j = 0; j < iN; ++j)
		{
			if (strNode[j] == '1')
			{
				vecNode[i].push_back(j);
			}
		}
	}

	for (int i = 0; i < iN; ++i)
	{
		if (vecIndex[i] == 0)
		{
			scc(i);
		}
	}

	vector<int> vecMax(iN + 1, 2000000000);
	for (int i = 0; i < iN; ++i)
	{
		vecMax[vecSCCNum[i]] = min(vecMax[vecSCCNum[i]], vecCost[i]);
	}

	int iAns = 0;
	for (int i = 1; i <= iN; ++i)
	{
		if (vecMax[i] != 2000000000)
		{
			iAns += vecMax[i];
		}
	}

	cout << iAns << "\n";
	return 0;
}
