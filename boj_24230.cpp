#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vecNode[200001];
vector<int> vecColor(200001, 0);

int dfs(int iN, int iPrev, int iColor)
{
	int iCount = 0;
	if (iColor != vecColor[iN])
	{
		++iCount;
		iColor = vecColor[iN];
	}
	for (int iNext : vecNode[iN])
	{
		if (iNext == iPrev) continue;
		iCount += dfs(iNext, iN, iColor);
	}
	return iCount;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	for (int i = 1; i <= iN; ++i) cin >> vecColor[i];
	for (int i = 1; i < iN; ++i)
	{
		int iS, iE;
		cin >> iS >> iE;
		vecNode[iS].push_back(iE);
		vecNode[iE].push_back(iS);
	}

	cout << dfs(1, 0, 0) << "\n";
	return 0;
}
