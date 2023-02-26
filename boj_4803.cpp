#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vecNode[501];
int Visited[501] = { 0, };

bool DFS(int iNum, int iBefore)
{
	for (int iNext : vecNode[iNum])
	{
		if (iNext == iBefore) continue;
		if (Visited[iNext]) return false;
		Visited[iNext] = true;
		if (!DFS(iNext, iNum)) return false;
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iTestCase = 0;

	while (true)
	{
		int iN, iM;
		cin >> iN >> iM;
		if (iN == 0 && iM == 0) break;

		++iTestCase;

		for (int i = 1; i <= iN; ++i)
		{
			Visited[i] = 0;
			vecNode[i].clear();
		}

		while (iM--)
		{
			int iS, iE;
			cin >> iS >> iE;
			vecNode[iS].push_back(iE);
			vecNode[iE].push_back(iS);
		}

		int iAns = 0;
		for (int i = 1; i <= iN; ++i)
		{
			if (!Visited[i])
			{
				Visited[i] = true;
				if (DFS(i, 0))
				{
					++iAns;
				}
			}
		}
		if (iAns == 0)
		{
			cout << "Case " << iTestCase << ": No trees.\n";
		}
		else if (iAns == 1)
		{
			cout << "Case " << iTestCase << ": There is one tree.\n";
		}
		else
		{
			cout << "Case " << iTestCase << ": A forest of " << iAns << " trees.\n";
		}
	}

	return 0;
}
