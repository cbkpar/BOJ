#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<vector<int>> vecNode(1001, vector<int>());
vector<string> vecName(1001, "");

void dfs(int iNow, int iLevel)
{
	for (int i = 0;i < iLevel;++i)
	{
		cout << ".";
	}
	cout << vecName[iNow] << "\n";

	for (int iNext : vecNode[iNow])
	{
		dfs(iNext, iLevel + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	for (int i = 1;i <= iN;++i)
	{
		int iNum;
		cin >> iNum;
		vecNode[iNum].push_back(i);
		cin >> vecName[i];
	}

	dfs(1, 0);

	return 0;
}
