#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int g_iIndex = 0;
int g_iAns = 0;
vector<vector<int>> vecNode(200001, vector<int>());
vector<int> vecIndex(200001, 0);
vector<bool> vecFinished(200001, false);
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

	int iN, iM;
	cin >> iN >> iM;

	for (int i = 0; i < iM; ++i)
	{
		int iS, iE;
		cin >> iS >> iE;
		vecNode[iS].push_back(iE);
	}

	for (int i = 1; i <= iN; ++i)
	{
		if (vecIndex[i] == 0)
		{
			scc(i);
		}
	}

	cout << (g_iAns == iN ? "Yes" : "No") << "\n";
	return 0;
}
