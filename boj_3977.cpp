#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int g_iIndex = 0;
vector<vector<int>> vecNode;
vector<int> vecIndex;
vector<bool> vecFinished;

int g_iSCCIndex = 0;
vector<int> vecSCCNum;
vector<int> vecSCCCount;
vector<bool> vecSCCTarget;
stack<int> stNum;

vector<int> dp;

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
			++vecSCCCount[g_iSCCIndex];
			if (iNum == iNow) break;
		}
	}

	return iRet;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	for (int t = 0; t < iT; ++t)
	{
		int iN, iM;
		cin >> iN >> iM;

		g_iIndex = 0;
		vecNode = vector<vector<int>>(iN, vector<int>());
		vecIndex = vector<int>(iN, 0);
		vecFinished = vector<bool>(iN, false);

		g_iSCCIndex = 0;
		vecSCCNum = vector<int>(iN + 1, 0);
		vecSCCCount = vector<int>(iN + 1, 0);

		dp = vector<int>(iN + 1, 0);

		for (int i = 0; i < iM; ++i)
		{
			int iS, iE;
			cin >> iS >> iE;
			vecNode[iS].push_back(iE);
		}

		for (int i = 0; i < iN; ++i)
		{
			if (vecIndex[i] == 0)
			{
				SCC(i);
			}
		}

		vecSCCTarget = vector<bool>(g_iSCCIndex + 1, false);

		for (int i = 0; i < iN; ++i)
		{
			for (int iNext : vecNode[i])
			{
				if (vecSCCNum[i] != vecSCCNum[iNext])
				{
					vecSCCTarget[vecSCCNum[iNext]] = true;
				}
			}
		}

		int iAns = 0;
		for (int i = 1;i <= g_iSCCIndex;++i)
		{
			if (!vecSCCTarget[i])
			{
				if (iAns == 0)
				{
					iAns = i;
				}
				else if (iAns > 0)
				{
					iAns = -1;
				}
			}
		}

		vector<int> vecAns;
		for (int i = 0; i < iN; ++i)
		{
			if (vecSCCNum[i] == iAns)
			{
				vecAns.push_back(i);
			}
		}

		int iSize = vecAns.size();
		if (iSize == 0)
		{
			cout << "Confused" << "\n";
		}
		else
		{
			for (int i = 0; i < iSize; ++i)
			{
				cout << vecAns[i] << "\n";
			}
		}
		cout << "\n";
	}
	return 0;
}
