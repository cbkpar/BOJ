int g_iIndex = 0;
vector<vector<int>> vecNode(200001, vector<int>());
vector<int> vecIndex(200001, 0);
vector<bool> vecFinished(200001, false);
stack<int> stNum;

int g_iSCCIndex = 0;
vector<int> vecSCCNum(200001, 0);
vector<int> vecSCCCount(200001, 0);
vector<vector<int>> vecSCCNode(200001, vector<int>());

vector<int> dp(200001, 0);

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
			++vecSCCCount[g_iSCCIndex];
			if (iNow == iNum) break;
		}
	}

	return iRet;
}

int CalcNext(int iNum, int iN)
{
	int iRet = iNum;
	while (iNum > 0)
	{
		iRet += iNum % 10;
		iNum /= 10;
	}
	iRet = (iRet - 1) % iN + 1;
	return iRet;
}

int SCCDFS(int iNum)
{
	dp[iNum] = vecSCCCount[iNum];
	for (int iNext : vecSCCNode[iNum])
	{
		if (dp[iNext] == 0)
		{
			dp[iNum] += SCCDFS(iNext);
		}
		else
		{
			dp[iNum] += dp[iNext];
		}
	}
	return dp[iNum];
}
