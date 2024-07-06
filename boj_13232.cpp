#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

int g_iIndex = 0;
int g_iAns = 0;
vector<vector<int>> vecNode(5001, vector<int>());
vector<int> vecIndex(5001, 0);
vector<bool> vecFinished(5001, false);
stack<int> stNum;

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
		int iCount = 0;

		while (!stNum.empty())
		{
			int iNum = stNum.top();
			vecFinished[iNum] = true;
			stNum.pop();
			++iCount;

			if (iNum == iNow) break;
		}

		g_iAns = max(g_iAns, iCount);
	}

	return iRet;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iD, iL;
	cin >> iD >> iL;

	for (int i = 0; i < iL; ++i)
	{
		int iS, iE;
		cin >> iS >> iE;
		vecNode[iS].push_back(iE);
	}

	for (int i = 1; i <= iD; ++i)
	{
		if (vecIndex[i] == 0)
		{
			scc(i);
		}
	}

	cout << g_iAns << "\n";
	return 0;
}
