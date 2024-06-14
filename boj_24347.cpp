#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<long long> vecNum(4, 0);
vector<bool> vecVisited(4, false);
long long lAns = 0;

void dfs(int iK, long long lSum)
{
	if (iK == 4)
	{
		lAns = max(lAns, lSum);
		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		if (!vecVisited[i])
		{
			vecVisited[i] = true;
			long long lTemp = lSum;
			long long lTemp2 = vecNum[i];
			if (lTemp2 == 0)
			{
				lTemp *= 10;
			}
			else
			{
				while (lTemp2)
				{
					lTemp *= 10;
					lTemp2 /= 10;
				}
				lTemp += vecNum[i];
			}
			dfs(iK + 1, lTemp);
			vecVisited[i] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 4; ++i)
	{
		cin >> vecNum[i];
	}

	dfs(0, 0);
	cout << lAns << "\n";
	return 0;
}
