#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int iN;
long long lAns;
vector<string> vecWord;
long long vecNum[10] = { 0, };
bool vecVisited[10] = { false, };
vector<bool> vecZeroPossible(10, true);

void dfs(int iK)
{
	if (iK == 10)
	{
		long long lSum = 0;
		for (int i = 0; i < iN; ++i)
		{
			long long lTemp = 0;
			int iSize = vecWord[i].size();
			for (int j = 0; j < iSize; ++j)
			{
				lTemp *= 10;
				lTemp += vecNum[vecWord[i][j] - 'A'];
			}
			lSum += lTemp;
		}
		lAns = max(lAns, lSum);
		return;
	}
	for (int i = 0; i < 10; ++i)
	{
		if (!vecVisited[i])
		{
			if (i == 0 && !vecZeroPossible[iK]) continue;
			vecVisited[i] = true;
			vecNum[iK] = i;
			dfs(iK + 1);
			vecVisited[i] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> iN;
	for (int i = 0; i < iN; ++i)
	{
		string strWord;
		cin >> strWord;
		vecWord.push_back(strWord);
		vecZeroPossible[strWord[0] - 'A'] = false;
	}
	lAns = 0;
	dfs(0);
	cout << lAns << "\n";
	return 0;
}
