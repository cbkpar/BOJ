#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int g_iIndex = 0;
vector<vector<int>> vecNode(20003, vector<int>());
vector<int> vecIndex(20003, 0);
vector<bool> vecFinished(20003, false);

int g_iSCCIndex = 0;
vector<int> vecSCCNum(20003, 0);
stack<int> stNum;

int SCC(int iNow)
{
	int iRet = vecIndex[iNow] = ++g_iIndex;
	stNum.push(iNow);

	for (int iNext : vecNode[iNow])
	{
		if (vecIndex[iNext] == 0)
		{
			iRet = min(iRet, SCC(iNext));
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
			
			vecFinished[iNum] = true;
			vecSCCNum[iNum] = g_iSCCIndex;
			if (iNum == iNow) break;
		}
	}

	return iRet;
}

int IndexConvert(int iNum)
{
	int iRet = abs(iNum) * 2;
	if (iNum > 0)
	{
		--iRet;
	}
	return iRet;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;

	for (int i = 0; i < iN; ++i)
	{
		int iA, iB;
		cin >> iA >> iB;

		vecNode[IndexConvert(-iA)].push_back(IndexConvert(iB));
		vecNode[IndexConvert(-iB)].push_back(IndexConvert(iA));
	}

	for (int i = 1; i <= iM * 2; ++i)
	{
		if (vecIndex[i] == 0)
		{
			SCC(i);
		}
	}

	bool bPossible = true;
	for (int i = 1; i <= iM; ++i)
	{
		if (vecSCCNum[i * 2 - 1] == vecSCCNum[i * 2])
		{
			bPossible = false;
		}
	}

	cout << (bPossible ? "^_^" : "OTL") << "\n";
	return 0;
}
