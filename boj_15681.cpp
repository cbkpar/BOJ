#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[200001] = { 0, };
vector<int> Node[200001];

int DFS(int iNum, int iBefore)
{
	if (dp[iNum] != -1) return dp[iNum];
	int iCount = 1;
	for (int iNext : Node[iNum])
	{
		if (iNext == iBefore) continue;
		iCount += DFS(iNext, iNum);
	}
	return dp[iNum] = iCount;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iR, iQ;
	cin >> iN >> iR >> iQ;

	for (int i = 1; i < iN; ++i)
	{
		int iS, iE;
		cin >> iS >> iE;
		Node[iS].push_back(iE);
		Node[iE].push_back(iS);
	}
	for (int i = 1; i <= iN; ++i) dp[i] = -1;
	DFS(iR, -1);

	while (iQ--)
	{
		int iNum;
		cin >> iNum;
		cout << dp[iNum] << "\n";
	}
	return 0;
}
