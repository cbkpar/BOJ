#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[10001][2] = { 0, };
int Value[10001] = { 0, };
vector<int> Node[10001];

void DFS(int iNum, int iBefore)
{
	dp[iNum][0] = 0;
	dp[iNum][1] = Value[iNum];
	for (int iNext : Node[iNum])
	{
		if (iNext == iBefore) continue;
		DFS(iNext, iNum);
		dp[iNum][0] += max(dp[iNext][0], dp[iNext][1]);
		dp[iNum][1] += dp[iNext][0];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	for (int i = 1; i <= iN; ++i)
	{
		cin >> Value[i];
		dp[i][0] = dp[i][1] = -1;
	}
	for (int i = 1; i < iN; ++i)
	{
		int iS, iE;
		cin >> iS >> iE;
		Node[iS].push_back(iE);
		Node[iE].push_back(iS);
	}

	int iAns = 0;
	for (int i = 1; i <= iN; ++i)
	{
		if (dp[i][0] == -1)
		{
			DFS(i, -1);
			iAns += max(dp[i][0], dp[i][1]);
		}
	}
	cout << iAns << "\n";
	return 0;
}
